
#include <precompiled.h>
#include <OISMain.h>

OISMain::OISMain()
{
    mKeyboard = NULL;
    mMouse = NULL;
    mInputManager = NULL;
}

OISMain::~OISMain()
{
}

//inicjalizacja OIS.
void OISMain::Initialize(Ogre::RenderWindow* mWindow)
{
    //Wpis do logow.
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
    mInputManager = OIS::InputManager::createInputSystem( pl );

    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject(OIS::OISKeyboard, true));
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject(OIS::OISMouse, true));
    windowResized(mWindow);
}

//miejsce do klikania myszka.
void OISMain::windowResized(Ogre::RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);
 
    const OIS::MouseState &ms = mMouse->getMouseState();
    ms.width = width;
    ms.height = height;
}

//odlacza OIS od okienka. bardzo wazne pod linuxem.
void OISMain::windowClosed(Ogre::RenderWindow* rw)
{
    if (mInputManager)
    {
        mInputManager->destroyInputObject( mMouse );
        mInputManager->destroyInputObject( mKeyboard );

        OIS::InputManager::destroyInputSystem(mInputManager);
        mInputManager = 0;
    }
}
