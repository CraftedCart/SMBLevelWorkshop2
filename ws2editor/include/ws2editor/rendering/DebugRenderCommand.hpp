/**
 * @file
 * @brief Header for the DebugRenderCommand class WS2EDITOR_EXPORT
 */

#ifndef SMBLEVELWORKSHOP2_WS2EDITOR_RENDERING_DEBUGRENDERCOMMAND_HPP
#define SMBLEVELWORKSHOP2_WS2EDITOR_RENDERING_DEBUGRENDERCOMMAND_HPP

#include "ws2editor_export.h"
#include "ws2editor/CachedGlMesh.hpp"
#include "ws2editor/rendering/IRenderCommand.hpp"
#include "ws2editor/RenderManager.hpp"

namespace WS2Editor {
    namespace Rendering {
        class WS2EDITOR_EXPORT DebugRenderCommand : public IRenderCommand {
            protected:
                RenderManager *renderManager;
                glm::mat4 viewMatrix;
                glm::mat4 projMatrix;
                btDynamicsWorld *dynamicsWorld;
                PhysicsDebugDrawer *debugDrawer;

            public:
                DebugRenderCommand(
                        RenderManager *renderManager,
                        glm::mat4 viewMatrix,
                        glm::mat4 projMatrix,
                        btDynamicsWorld *dynamicsWorld,
                        PhysicsDebugDrawer *debugDrawer
                        );

                virtual void draw() override;
        };
    }
}

#endif

