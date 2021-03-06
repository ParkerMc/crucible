#pragma once

#include <crucible/GameObject.hpp>
#include <btBulletDynamicsCommon.h>
#include <vector>

class CrucibleBulletDebugDraw;

class Scene {
private:
    std::vector<GameObject*> objects;

    btDefaultCollisionConfiguration* collisionConfiguration;
    btCollisionDispatcher* dispatcher;
    btBroadphaseInterface* overlappingPairCache;
    btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;
    CrucibleBulletDebugDraw* debugDrawer;

    bool physicsEnabled = false;

public:
    ~Scene();

    GameObject &createObject(const Transform &transform, const std::string &name);

    GameObject &createMeshObject(const Mesh &mesh, const Material &material, const Transform &transform,
                                        const std::string &name);

    void render();

    void update(float delta);

    void setupPhysicsWorld();

    btDiscreteDynamicsWorld *getBulletWorld();

    bool isPhysicsEnabled() const;
};