#include <precompiled.h>
#include <WorldObject.h>
#include <GameEngine.h>

WorldObject::WorldObject(Ogre::String name, unsigned int size_x, unsigned int size_y, unsigned int size_z, Ogre::String mesh, bool shadow = true) : Unit(name)
{
    setObjectSize(size_x, size_y, size_z);
    setShadow(shadow);
    WorldObject::ObjectNode = sGameEngine->mSceneMgr->getRootSceneNode()->createChildSceneNode();
    WorldObject::Entity = sGameEngine->mSceneMgr->createEntity(mesh+".mesh");
    WorldObject::Entity->setCastShadows(shadow);
    Ogre::AnimationStateIterator anim_iter = WorldObject::Entity->getAllAnimationStates()->getAnimationStateIterator();
    if(anim_iter.hasMoreElements()) //Crash !!! I dont know why...
    {
        WorldObject::Animation = new AnimationBlender(WorldObject::Entity);
        Ogre::AnimationState * first = (WorldObject::Entity->getAllAnimationStates()->getAnimationStateIterator().getNext());
        WorldObject::Animation->init(first->getAnimationName(),true);
        sGameEngine->RegisterBlendedAnimation(WorldObject::Animation);
    }
}
WorldObject::WorldObject(Ogre::String name, unsigned int size_x, unsigned int size_y, unsigned int size_z, unsigned int x_pos, unsigned int y_pos, unsigned int z_pos, Ogre::String mesh, bool shadow = true) : Unit(name, x_pos, y_pos, z_pos)
{
    WorldObject::WorldObject(name, size_x, size_y, size_z, mesh, shadow);
}
WorldObject::~WorldObject()
{
    delete[] WorldObject::Entity;
    delete[] WorldObject::ObjectNode;
}
void WorldObject::setObjectSize(unsigned int x, unsigned int y, unsigned int z)
{
    WorldObject::ObjectSize.x = x;
    WorldObject::ObjectSize.y = y;
    WorldObject::ObjectSize.z = z;
}
void WorldObject::setShadow(bool shadow)
{
    WorldObject::CastShadow = shadow;
}
void WorldObject::setAnimation(AnimationBlender * animation)
{
    WorldObject::Animation = animation;
}
bool WorldObject::itCastShadow()
{
    return WorldObject::CastShadow;
}
AnimationBlender * WorldObject::getAnimation()
{
    return WorldObject::Animation;
}
size_struct WorldObject::getObjectSize()
{
    return WorldObject::ObjectSize;
}
void WorldObject::BlendAnimation(char * animation, double duration, AnimationBlender::BlendingTransition trans = AnimationBlender::BlendWhileAnimating, bool loop = true)
{
    getAnimation()->blend(animation, trans, duration, loop);
}
void WorldObject::setEntity(Ogre::Entity * entity)
{
    WorldObject::Entity = entity;
}
void WorldObject::setNode(Ogre::SceneNode * node)
{
    WorldObject::ObjectNode = node;
}