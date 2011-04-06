#ifndef _OISMain_H__
#define _OISMain_H__

#include<OIS.h>
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

    //miejsce do klikania myszk¹.
    void windowResized(Ogre::RenderWindow* rw);

    //od³¹cza OIS od okienka. bardzo wa¿ne pod linuxem.
    virtual void windowClosed(Ogre::RenderWindow* rw);

};

#endif