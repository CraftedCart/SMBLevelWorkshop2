/**
 * @file
 * @brief Header for the WormholeSceneNode class
 */

#ifndef SMBLEVELWORKSHOP2_WS2COMMON_SCENE_WORMHOLESCENENODE_HPP
#define SMBLEVELWORKSHOP2_WS2COMMON_SCENE_WORMHOLESCENENODE_HPP

#include "scene/SceneNode.hpp"

namespace WS2Common {
    namespace Scene {
        class WormholeSceneNode : public SceneNode {
            protected:
                /**
                 * @brief Where this wormhole should lead to
                 */
                WormholeSceneNode *destination;

            public:
                WormholeSceneNode(const QString name);

                /**
                 * @brief Getter for destination
                 *
                 * @return A pointer to the destination WormholeSceneNode
                 */
                WormholeSceneNode* getDestination();

                /**
                 * @brief Setter for destination
                 *
                 * @param type A pointer to the destination wormhole to set this as
                 */
                void setDestination(WormholeSceneNode *destination);
        };
    }
}

#endif

