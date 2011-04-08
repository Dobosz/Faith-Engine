#ifndef _MainListener_H__
#define _MainListener_H__

#include <precompiled.h>
#include <vector>

using namespace Ogre;

class MainListener : public FrameListener
{
public:
    std::vector<AnimationState *> AnimationArray;
    MainListener(void);
    ~MainListener(void);
    bool frameStarted(const FrameEvent& evt);
    bool frameEnded(const FrameEvent& evt);
    bool shutdown;
};
#endif
