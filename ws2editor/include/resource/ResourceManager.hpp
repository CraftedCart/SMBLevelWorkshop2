/**
 * @file
 * @brief Header for the WS2Editor::Resource::ResourceManager namespace
 */

#ifndef SMBLEVELWORKSHOP2_RESOURCEMANAGER_HPP
#define SMBLEVELWORKSHOP2_RESOURCEMANAGER_HPP

#include "resource/AbstractResource.hpp"
#include "resource/ResourceMesh.hpp"
#include <QVector>
#include <QFile>
#include <QDir>
#include <assimp/scene.h>

namespace WS2Editor {
    namespace Resource {

        /**
         * @brief Stores and manages various runtime resources
         */
        namespace ResourceManager {
            /**
             * @brief Internal members for use by ResourceManager
             */
            namespace ResourceManagerInternal {
                /**
                 * @brief Loads a model into the scene.
                 *
                 * @param file The model file to append
                 * @param shouldLoad Should the model be loaded into the GPU
                 *
                 * @return A vector of added meshes
                 */
                QVector<ResourceMesh*> loadModel(QFile &file, bool shouldLoad = false);

                /**
                 * @brief Append a model to the scene from the file given
                 *
                 * @param filePath The file path to the model file to append
                 * @param shouldLoad Should the model be loaded into the GPU
                 *
                 * @return A vector of added meshes
                 */
                QVector<ResourceMesh*> addModelFromFile(const char *filePath, bool shouldLoad = false);

                /**
                 * @brief Recursive function that keeps calling itself for each child node in the parent node given.
                 *        This function is used to convert data generated by Assimp into data useable by WS2.
                 *
                 * @param node The parent node to process. This is usually the root node if calling it yourself.
                 * @param scene The scene that the node belongs to
                 * @param globalTransform A matrix transformation to apply to all vertices
                 * @param parentDir The parent directory of the file
                 * @param meshVector A reference to a vector that will be populated with all meshes processed
                 * @param shouldLoad Should the model be loaded into the GPU
                 */
                void processNode(
                        const aiNode *node,
                        const aiScene *scene,
                        const glm::mat4 globalTransform,
                        const QString *filePath,
                        const QDir *parentDir,
                        QVector<ResourceMesh*> &meshVector,
                        bool shouldLoad = false
                        );

                /**
                 * @brief Converts an aiMesh into a WS2Editor::Model::Mesh
                 *
                 * @param mesh The aiMesh to convert
                 * @param scene The scene that the aiMesh belongs to
                 * @param globalTransform A matrix transformation to apply to all vertices
                 * @param parentDir The parent directory of the file
                 * @param shouldLoad Should the model be loaded into the GPU
                 *
                 * @return The converted mesh
                 */
                Model::MeshSegment* processMeshSegment(
                        const aiMesh *mesh,
                        const aiScene *scene,
                        const glm::mat4 globalTransform,
                        const QDir *parentDir,
                        bool shouldLoad = false
                        );

                /**
                 * @brief Loads textures for a material
                 *
                 * @param material The material to load textures for
                 * @param type The type of textures to load
                 * @param parentDir The parent directory of the file
                 * @param shouldLoad Should the model be loaded into the GPU
                 *
                 * @return A vector of textures
                 */
                QVector<Resource::ResourceTexture*> loadMaterialTextures(
                        aiMaterial *material,
                        aiTextureType type,
                        const QDir *parentDir,
                        bool shouldLoad = false
                        );
            }

            /**
             * @brief Getter for the resources vector
             *
             * @return A reference to the resources vector
             */
            QVector<AbstractResource*>& getResources();

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

#include "resource/ResourceManager.ipp"

#endif

