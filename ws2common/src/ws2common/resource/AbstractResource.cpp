#include "ws2common/resource/AbstractResource.hpp"

namespace WS2Common {
    namespace Resource {
        AbstractResource::~AbstractResource() {
            if (isLoaded()) unload();
        }

        void AbstractResource::setId(const QString &id) {
            this->id = id;
        }

        const QString& AbstractResource::getId() const {
            return id;
        }

        void AbstractResource::setFilePath(const QString &filePath) {
            filePaths.clear();
            filePaths.append(filePath);
        }

        void AbstractResource::addFilePath(const QString &filePath) {
            filePaths.append(filePath);
        }

        const QString* AbstractResource::getFirstFilePath() const {
            if (filePaths.size() > 0) {
                return &filePaths.at(0);
            } else {
                return nullptr;
            }
        }

        const QVector<QString>& AbstractResource::getFilePaths() const {
            return filePaths;
        }

        void AbstractResource::load() {
            loaded = true;
        }

        void AbstractResource::unload() {
            loaded = false;
        }

        bool AbstractResource::isLoaded() const {
            return loaded;
        }
    }
}

