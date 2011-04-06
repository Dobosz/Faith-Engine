#ifndef _OISMain_H__
#define _OISMain_H__

#include<../include/OIS/OIS.h>
#include<Ogre.h>

using namespace OIS;

class OISMain
{
public:
    InputManager* mInputManager;
    Mouse*    mMouse;
    Keyboard* mKeyboard;

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