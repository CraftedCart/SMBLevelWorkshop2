/**
 * @file
 * @brief Header for the CachedGlTexture class
 */

#ifndef SMBLEVELWORKSHOP2_WS2EDITOR_CACHEDGLTEXTURE_HPP
#define SMBLEVELWORKSHOP2_WS2EDITOR_CACHEDGLTEXTURE_HPP

#include "ws2editor_export.h"
#include "ws2editor/glplatform.hpp"
#include <QElapsedTimer>

namespace WS2Editor {

    /**
     * @note The destructor will not delete the GL texture - it is your job to ensure that the correct GL context is bound and delete it yourself
     */
    class WS2EDITOR_EXPORT CachedGlTexture {
        protected:
            QElapsedTimer lastAccessTimer;

            GLuint textureId;

        public:
            void updateAccessTimer();
            QElapsedTimer& getLastAccessTimer();

            void setTextureId(GLuint textureId);
            GLuint getTextureId();
    };
}

#endif

