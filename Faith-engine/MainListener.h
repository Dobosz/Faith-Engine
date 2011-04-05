#ifndef _MainListener_H__
#define _MainListener_H__

#include <Ogre.h>

using namespace Ogre;

class MainListener : public FrameListener
{
public:
    MainListener(void);
    ~MainListener(void);
    bool frameStarted(const FrameEvent& evt);
    bool frameEnded(const FrameEvent& evt);
    bool shutdown;
};
#endif
