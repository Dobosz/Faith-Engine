#include <MainListener.h>
#include <GameEngine.h>

//Class MainListener inheriets from Oger::Listener. If function "frameStarted" or "frameEnded" returns false, Ogre will shutdown the process. That goes for every listener registret to the root.

MainListener::MainListener(void)
    {
    }


MainListener::~MainListener(void)
    {
    }

bool MainListener::frameStarted(const FrameEvent& evt)
    {
        GameEngine::getSingleton()->mCamNode->pitch(Ogre::Degree(evt.timeSinceLastFrame));
        return true;
    }

bool MainListener::frameEnded(const FrameEvent& evt)
    {
        return true;
    }