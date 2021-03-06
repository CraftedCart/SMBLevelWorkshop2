/**
 * @file
 * @brief Header for the LoadGlTextureTask class
 */

#ifndef SMBLEVELWORKSHOP2_WS2EDITOR_TASK_LOADGLTEXTURETASK_HPP
#define SMBLEVELWORKSHOP2_WS2EDITOR_TASK_LOADGLTEXTURETASK_HPP

#include "ws2editor_export.h"
#include "ws2editor/task/Task.hpp"
#include "ws2common/resource/ResourceTexture.hpp"
#include <QImage>

namespace WS2Editor {
    namespace Task {
        class WS2EDITOR_EXPORT LoadGlTextureTask : public Task {
            Q_OBJECT

            protected:
                const WS2Common::Resource::ResourceTexture &tex;

            public:
                LoadGlTextureTask(const WS2Common::Resource::ResourceTexture &tex);

                void runTask(Progress *prog) override;
                QString getTranslatedMessage() override;

            signals:
                void addTexture(const QImage loadedImage, const WS2Common::Resource::ResourceTexture *tex);
        };
    }
}

#endif

