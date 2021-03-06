#include "ws2editor/physics/PhysicsContainer.hpp"
#include "ws2editor/MathUtils.hpp"
#include "ws2common/MathUtils.hpp"

namespace WS2Editor {
    namespace Physics {
        using namespace WS2Common;
        using namespace WS2Common::Resource;
        using namespace WS2Common::Scene;

        PhysicsContainer::PhysicsContainer(
                SceneNode *node,
                const QVector<ResourceMesh*> meshes,
                const Transform &transform) {
            glm::quat rotQuat = MathUtils::eulerZyxToGlmQuat(transform.getRotation());

            //Construct mesh collision shape
            btTriangleMesh *triMesh = new btTriangleMesh();

            QVector<WS2Common::Model::MeshSegment*> segments;
            for (ResourceMesh *mesh : meshes) segments.append(mesh->getMeshSegments());

            //Loop over all segments in the mesh
            for (int i = 0; i < segments.size(); i++) {
                const WS2Common::Model::MeshSegment *segment = segments.at(i);

                for (int j = 0; j < segment->getIndices().size(); j += 3) {
                    triMesh->addTriangle(
                            MathUtils::toBtVector3(segment->getVertices().at(segment->getIndices().at(j)).position),
                            MathUtils::toBtVector3(segment->getVertices().at(segment->getIndices().at(j + 1)).position),
                            MathUtils::toBtVector3(segment->getVertices().at(segment->getIndices().at(j + 2)).position)
                            );
                }
            }

            physicsCollisionShape = new btBvhTriangleMeshShape(triMesh, true);

            physicsMotionState = new btDefaultMotionState(btTransform(
                        btQuaternion(rotQuat.x, rotQuat.y, rotQuat.z, rotQuat.w),
                        btVector3(MathUtils::toBtVector3(transform.getPosition()))
                        ));
            physicsCollisionShape->setLocalScaling(MathUtils::toBtVector3(transform.getScale()));

            btRigidBody::btRigidBodyConstructionInfo constructionInfo(
                    0, //kg mass - 0 = static object
                    physicsMotionState,
                    physicsCollisionShape,
                    btVector3(0.0f, 0.0f, 0.0f) //Local inertia
                    );

            physicsRigidBody = new btRigidBody(constructionInfo);

            physicsRigidBody->setUserPointer(node); //The rigid body is bound to the node
        }

        PhysicsContainer::PhysicsContainer(
                SceneNode *node,
                ResourceMesh* mesh,
                const Transform &transform) :
            PhysicsContainer(node, QVector<ResourceMesh*> {mesh}, transform) {}

        PhysicsContainer::~PhysicsContainer() {
            delete physicsCollisionShape;
            delete physicsMotionState;
            delete physicsRigidBody;
        }

        void PhysicsContainer::updateTransform(Transform &transform) {
            glm::quat rotQuat = MathUtils::eulerZyxToGlmQuat(transform.getRotation());

            btTransform bulletTransform(
                    btQuaternion(rotQuat.x, rotQuat.y, rotQuat.z, rotQuat.w),
                    btVector3(MathUtils::toBtVector3(transform.getPosition()))
                    );

            //TODO: Not world
            physicsMotionState->setWorldTransform(bulletTransform);
            physicsRigidBody->setWorldTransform(bulletTransform);

            physicsCollisionShape->setLocalScaling(MathUtils::toBtVector3(transform.getScale()));
        }

        btRigidBody* PhysicsContainer::getRigidBody() {
            return physicsRigidBody;
        }
    }
}

