#include "ws2common/MessageHandler.hpp"
#include "ws2common/EnumGameVersion.hpp"
#include "ws2common/config/XMLConfigParser.hpp"
#include "ws2lz/SMB2LzExporter.hpp"
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFile>
#include <QBuffer>
#include <QDataStream>
#include <QDebug>

int main(int argc, char *argv[]) {
    qInstallMessageHandler(WS2Common::messageHandler);

    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("ws2frontend");

    QCommandLineParser parser;
    parser.setApplicationDescription("An interface for ws2lz, to export LZ files for use within Super Monkey Ball");
    parser.addHelpOption();

    parser.addOptions({
            {{"c", "config"}, QCoreApplication::translate("main", "Input path to the XML configuration file."), QCoreApplication::translate("main", "configuration file")},
            {{"o", "output"}, QCoreApplication::translate("main", "Output path to an uncompressed LZ file."), QCoreApplication::translate("main", "uncompressed output file")},
            {{"s", "compressed-output"}, QCoreApplication::translate("main", "Output path to a compressed LZ file."), QCoreApplication::translate("main", "output file")},
            {{"g", "game-version"}, QCoreApplication::translate("main", "The version of SMB to generate an LZ file for (1/2/deluxe)."), QCoreApplication::translate("main", "version")}
            });

    parser.process(app);

    //Some variables
    WS2Common::EnumGameVersion gameVersion = WS2Common::EnumGameVersion::SUPER_MONKEY_BALL_2;

    if (app.arguments().length() == 1) {
        //No arguments - print help
        parser.showHelp(EXIT_FAILURE);
    }

    if (!parser.parse(QCoreApplication::arguments())) {
        QString err = parser.errorText();
        qCritical().noquote() << err;
        return EXIT_FAILURE;
    }

    //Check for a valid input
    if (!parser.isSet("c")) {
        qCritical().noquote() << QCoreApplication::translate("main", "No confiuration file specified. Use --help for more info.");
        return EXIT_FAILURE;
    }

    //Check for a valid output
    if (!(parser.isSet("o") || parser.isSet("s"))) {
        qCritical().noquote() << QCoreApplication::translate("main", "No output file specified. Use --help for more info.");
        return EXIT_FAILURE;
    }

    //Check that the game version was specified, otherwise default to SMB 2
    if (!parser.isSet("g")) {
        qWarning().noquote() << QCoreApplication::translate("main", "No game version specified - defaulting to Super Monkey Ball 2 - Use --game-version to specify a different one");
    } else {
        //The --game-version switch was set
        //Check that the game version is valid
        if (parser.value("g") == "1") {
            gameVersion = WS2Common::EnumGameVersion::SUPER_MONKEY_BALL_1;
        } else if (parser.value("g") == "2") {
            gameVersion = WS2Common::EnumGameVersion::SUPER_MONKEY_BALL_2;
        } else if (parser.value("g") == "deluxe") {
            gameVersion = WS2Common::EnumGameVersion::SUPER_MONKEY_BALL_DELUXE;
        } else {
            //Invalid version
            qCritical().noquote() << QCoreApplication::translate("main", "Invalid game version specified. Use --help for more info.");
        }
    }

    //NYI warning
    qInfo() << "Reading configuration...";
    QFile configFile(parser.value("c"));
    configFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString config = configFile.readAll();
    configFile.close();

    qInfo() << "Parsing configuration...";
    WS2Common::Config::XMLConfigParser confParser;
    WS2Common::Stage *stage = confParser.parseStage(config);
    qInfo() << stage->getRootNode();

    QBuffer buf;
    buf.open(QIODevice::ReadWrite);
    QDataStream dStream(&buf);

    qInfo() << "Exporting file...";
    if (gameVersion == WS2Common::EnumGameVersion::SUPER_MONKEY_BALL_1) {
        qCritical() << "SMB 1 export not yet implemented";
    } else if (gameVersion == WS2Common::EnumGameVersion::SUPER_MONKEY_BALL_2) {
        WS2Lz::SMB2LzExporter exporter;

        exporter.generate(dStream, *stage);
    }

    buf.seek(0);
    //Write the uncompressed file if requested
    if (parser.isSet("o")) {
        QFile o(parser.value("o"));
        o.open(QIODevice::WriteOnly);
        o.write(buf.data());
        o.close();
    }

    //TODO: Compression

    buf.close();

    delete stage;

    return EXIT_SUCCESS;
}
