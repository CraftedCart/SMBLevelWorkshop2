/**
 * @file
 * @brief Header for the RestartCommand class
 */

#ifndef SMBLEVELWORKSHOP2_WS2EDITOR_COMMAND_RESTARTCOMMAND_HPP
#define SMBLEVELWORKSHOP2_WS2EDITOR_COMMAND_RESTARTCOMMAND_HPP

#include "ws2editor_export.h"
#include "ws2editor/command/ICommandHandler.hpp"

namespace WS2Editor {
    namespace Command {
        class WS2EDITOR_EXPORT RestartCommand : public ICommandHandler {
            public:
                virtual QString getCommand() override;
                virtual CommandReply executeCommand(QString command) override;
        };
    }
}

#endif

