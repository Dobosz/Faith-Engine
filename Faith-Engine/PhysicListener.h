#ifndef _PhysicListener_H__
#define _PhysicListener_H__

#include <precompiled.h>

class PhysicListener : public Ogre::FrameListener
{
public:
    PhysicListener(void);
    ~PhysicListener(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
};
#endif