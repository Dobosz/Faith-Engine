#include <MainListener.h>
#include <GameEngine.h>

//Class MainListener inheriets from Oger::Listener. If function "frameStarted" or "frameEnded" returns false, Ogre will shutdown the process. That goes for every listener registret to the root.

MainListener::MainListener(void)
    {
        shutdown = false;
    }

MainListener::~MainListener(void)
    {
        shutdown = true;
    }

bool MainListener::frameStarted(const FrameEvent& evt)
    {
        GameEngine::getEngine()->mCamNode->roll(Ogre::Degree(evt.timeSinceLastFrame*15)); //You can sey the "15" is a kind of speed. Its crushal to do actions according to timeSinceLastFrame.
        if(GameEngine::getEngine()->mWindow->isClosed())
            shutdown = true;
        return !shutdown;
    }

bool MainListener::frameEnded(const FrameEvent& evt)
    {
        return !shutdown;
    }