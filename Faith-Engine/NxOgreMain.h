#pragma once
#include <Ogre.h>
#include <NxOgre.h>
#include <NxOgreOGRE3D.h>
class NxOgreMain
{
public:

    NxOgre::World* mWorld;
    NxOgre::Scene* mScene;
    OGRE3DRenderSystem* mRenderSystem;
            
    NxOgreMain(void)
    ~NxOgreMain(void)
    {
    }
};

