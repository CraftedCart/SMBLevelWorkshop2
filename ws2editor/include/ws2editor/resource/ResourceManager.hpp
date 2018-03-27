/**
 * @file
 * @brief Header for the WS2Editor::Resource::ResourceManager namespace
 */

#ifndef SMBLEVELWORKSHOP2_WS2EDITOR_RESOURCEMANAGER_HPP
#define SMBLEVELWORKSHOP2_WS2EDITOR_RESOURCEMANAGER_HPP

#include "ws2common/resource/ResourceMesh.hpp"
#include <QVector>
#include <QFile>
#include <QDir>
#include <QMutex>

namespace WS2Editor {
    namespace Resource {
        /**
         * @brief Stores and manages various runtime resources
         */
        namespace ResourceManager {
            using namespace WS2Common::Resource;

            /**
             * @brief Use this when modifying the resources vector, to ensure thread safety
             */
            extern QMutex resourcesMutex;

            /**
             * @brief Getter for the resources vector
             *
             * @return A reference to the resources vector
             */
            QVector<WS2Common::Resource::AbstractResource*>& getResources();

            /**
             * @brief Adds a resource to the WS2Editor::Resource::ResourceManager::resources vector
             * @note WS2Editor::Resource::ResourceManager should be the owner of all resources, therefore **do not** delete
             *       the pointer after adding the resource.
             *
             * @param res The resource to add
             */
            void addResource(AbstractResource *res);

            /**
             * @brief Unloads all registered resources if they are loaded
             */
            void unloadAllResources();

            /**
             * @brief Gets a resource originating from the given file path
             *
             * The resource is statically casted to the type T specified
             *
             * @tparam T The type to cast the resource to. This should be a pointer type.
             * @param filePath The file path of the resource
             *
             * @return A pointer to the resource if it already exists, or nullptr otherwise
             */
            template <class T>
            T getResourceFromFilePath(QString filePath);

            /**
             * @brief Addes the meshes in a 3D model to the resource manager
             *
             * @param file The model to load
             * @param shouldLoad Should the model be loaded into the GPU
             *
             * @return A vector of added meshes
             *
             * @throws IOException When failing to read the file
             * @throws RuntimeException When Assimp fails to generate an aiScene
             */
            QVector<ResourceMesh*> addModel(QFile &file, bool shouldLoad = false);

            /**
             * @brief Generates a unique resource ID prefixed with prefix
             *
             * @param prefix The prefix of the ID
             *
             * @return A unique resource ID, starting with prefix and ending with a number
             */
            QString generateUniqueId(QString prefix);
        }
    }
}

#include "ws2editor/resource/ResourceManager.ipp"

#endif

