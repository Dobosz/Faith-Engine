#include <precompiled.h>
#include <MovableWorldObject.h>
#include <GameEngine.h>

MovableWorldObject::MovableWorldObject(Ogre::String name, unsigned int size_x, unsigned int size_y, unsigned int size_z, unsigned int x_pos, unsigned int y_pos, unsigned int z_pos, Ogre::String mesh, double mass, bool shadow = true, int id = 0) : WorldObject(name, size_x, size_y, size_z, x_pos, y_pos, z_pos, mesh, shadow)
{
    Ogre::String NXS_name = "media:"+mesh+".nxs";
    NxOgre::Mesh* convexMesh = NxOgre::MeshManager::getSingleton()->load(NXS_name.c_str());
    NxOgre::Convex* convex = new NxOgre::Convex(convexMesh);
    Ogre::String Mesh_name = mesh+".mesh";
    MovableWorldObject::PhysicBody = sGameEngine->mPhysic->mRenderSystem->createBody(convex, NxOgre::Vec3(x_pos, y_pos, z_pos), Mesh_name); //Have to change posision to notGrid.
    MovableWorldObject::setEntity(MovableWorldObject::PhysicBody->getEntity());
    MovableWorldObject::setNode(MovableWorldObject::PhysicBody->getSceneNode());
    MovableWorldObject::PhysicBody->setMass(mass);
    MovableWorldObject::PhysicBody->setForceFieldMaterial(id);
}
MovableWorldObject::~MovableWorldObject()
{
}