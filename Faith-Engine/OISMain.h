#ifndef _OISMain_H__
#define _OISMain_H__

#include <precompiled.h>

class OISMain
{
public:
    OIS::InputManager* mInputManager;
    OIS::Mouse*    mMouse;
    OIS::Keyboard* mKeyboard;

    OISMain(void);

    ~OISMain(void);

    //inicjalizacja OIS.
    void Initialize(Ogre::RenderWindow* mWindow);

    //miejsce do klikania myszk�.
    void windowResized(Ogre::RenderWindow* rw);

    //od��cza OIS od okienka. bardzo wa�ne pod linuxem.
    virtual void windowClosed(Ogre::RenderWindow* rw);
};

#endif