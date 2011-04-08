
#include <precompiled.h>
#include <MainListener.h>
#include <GameEngine.h>

//Class MainListener inheriets from Oger::Listener. If function "frameStarted" or "frameEnded" returns false, Ogre will shutdown the process. That goes for every listener registret to the root.

MainListener::MainListener()
{
    shutdown = false;
}

MainListener::~MainListener()
{
    shutdown = true;
}

bool MainListener::frameStarted(const FrameEvent& evt)
{ 
    for(int i =0; i != AnimationArray.size(); i++)
    {
        AnimationArray[i]->addTime(evt.timeSinceLastFrame);
    }
    //sGameEngine->mCamNode->rotate(Vector3(0,0,50), Ogre::Degree(evt.timeSinceLastFrame*2),Node::TS_WORLD); //You can sey the "15" is a kind of speed. Its crushal to do actions according to timeSinceLastFrame.
    if (sGameEngine->mWindow->isClosed())
        shutdown = true;
    return !shutdown;
}

bool MainListener::frameEnded(const FrameEvent& evt)
{
    return !shutdown;
}

