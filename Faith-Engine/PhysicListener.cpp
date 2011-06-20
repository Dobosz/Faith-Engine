#include <precompiled.h>
#include <PhysicListener.h>
#include <GameEngine.h>

    PhysicListener::PhysicListener()
    {
    }
    PhysicListener::~PhysicListener()
    {
    }
    bool PhysicListener::frameRenderingQueued(const Ogre::FrameEvent& evt)
    {
        sGameEngine->mPhysic->mTime->advance(evt.timeSinceLastFrame);
        return true;
    }