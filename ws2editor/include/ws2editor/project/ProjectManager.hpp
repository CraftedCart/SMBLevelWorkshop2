/**
 * @file
 * @brief Header for the ProjectManager namespace
 */

#ifndef SMBLEVELWORKSHOP2_WS2EDITOR_PROJECT_PROJECTMANAGER_HPP
#define SMBLEVELWORKSHOP2_WS2EDITOR_PROJECT_PROJECTMANAGER_HPP

#include "ws2editor_export.h"
#include "ws2editor/project/Project.hpp"

namespace WS2Editor {
    namespace Project {
        namespace ProjectManager {
            /**
             * @brief Internal members for ProjectManager. It is recommended to use use the functions in ProjectManager
             *        over accessing the internals directly.
             */
            namespace ProjectManagerInternal {
                WS2EDITOR_EXPORT extern Project *activeProject;
            }

            /**
             * @brief Getter for activeProject
             *
             * @return A pointer to the active project
             */
            WS2EDITOR_EXPORT Project* getActiveProject();

            /**
             * @brief Creates a new empty project, and sets it as the active project
             */
            WS2EDITOR_EXPORT void newProject();
        }
    }
}

#endif

