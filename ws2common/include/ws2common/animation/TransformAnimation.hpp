/**
 * @file
 * @brief Header for the Animation class
 */

#ifndef SMBLEVELWORKSHOP2_WS2COMMON_ANIMATION_ANIMATION_HPP
#define SMBLEVELWORKSHOP2_WS2COMMON_ANIMATION_ANIMATION_HPP

#include "ws2common_export.h"
#include "ws2common/EnumPlaybackState.hpp"
#include "ws2common/animation/EnumLoopType.hpp"
#include "ws2common/animation/Keyframe.hpp"
#include <set>

namespace WS2Common {
    namespace Animation {
        struct WS2COMMON_EXPORT KeyframeCompare {
            //Comparison function for keyframe lookup - to ensure that keyframes are ordered by time
            bool operator() (const KeyframeF* lhs, const KeyframeF* rhs) const;
        };

        class WS2COMMON_EXPORT TransformAnimation {
            protected:
                EnumPlaybackState initialState;
                EnumLoopType loopType;
                float loopTime;

                //Not using a Qt container as none of them seem to have the ability to take compare functors
                std::set<KeyframeF*, KeyframeCompare> posXKeyframes;
                std::set<KeyframeF*, KeyframeCompare> posYKeyframes;
                std::set<KeyframeF*, KeyframeCompare> posZKeyframes;

                std::set<KeyframeF*, KeyframeCompare> rotXKeyframes;
                std::set<KeyframeF*, KeyframeCompare> rotYKeyframes;
                std::set<KeyframeF*, KeyframeCompare> rotZKeyframes;

                std::set<KeyframeF*, KeyframeCompare> scaleXKeyframes;
                std::set<KeyframeF*, KeyframeCompare> scaleYKeyframes;
                std::set<KeyframeF*, KeyframeCompare> scaleZKeyframes;

                std::set<KeyframeF*, KeyframeCompare> unknown1Keyframes;
                std::set<KeyframeF*, KeyframeCompare> unknown2Keyframes;

            public:
                EnumPlaybackState getInitialState() const;
                void setInitialState(EnumPlaybackState state);

                EnumLoopType getLoopType() const;
                void setLoopType(EnumLoopType initialState);

                float getLoopTime() const;
                void setLoopTime(float loopTime);

                std::set<KeyframeF*, KeyframeCompare>& getPosXKeyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getPosXKeyframes() const;
                std::set<KeyframeF*, KeyframeCompare>& getPosYKeyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getPosYKeyframes() const;
                std::set<KeyframeF*, KeyframeCompare>& getPosZKeyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getPosZKeyframes() const;

                std::set<KeyframeF*, KeyframeCompare>& getRotXKeyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getRotXKeyframes() const;
                std::set<KeyframeF*, KeyframeCompare>& getRotYKeyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getRotYKeyframes() const;
                std::set<KeyframeF*, KeyframeCompare>& getRotZKeyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getRotZKeyframes() const;

                std::set<KeyframeF*, KeyframeCompare>& getScaleXKeyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getScaleXKeyframes() const;
                std::set<KeyframeF*, KeyframeCompare>& getScaleYKeyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getScaleYKeyframes() const;
                std::set<KeyframeF*, KeyframeCompare>& getScaleZKeyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getScaleZKeyframes() const;

                std::set<KeyframeF*, KeyframeCompare>& getUnknown1Keyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getUnknown1Keyframes() const;
                std::set<KeyframeF*, KeyframeCompare>& getUnknown2Keyframes();
                const std::set<KeyframeF*, KeyframeCompare>& getUnknown2Keyframes() const;
        };
    }
}


#endif

