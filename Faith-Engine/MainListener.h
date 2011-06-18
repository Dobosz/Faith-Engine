#ifndef _MainListener_H__
#define _MainListener_H__

#include <precompiled.h>
#include <list>

using namespace Ogre;

class MainListener : public FrameListener
{
public:
    std::list<AnimationState *> AnimationArray;
    std::list<AnimationBlender *> AnimationBlendedArray;
    MainListener(void);
    ~MainListener(void);
    bool frameStarted(const FrameEvent& evt);
    bool frameEnded(const FrameEvent& evt);
    bool shutdown;
};
#endif
