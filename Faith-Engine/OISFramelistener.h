
#ifndef _OISFramelistener_H__
#define _OISFramelistener_H__

#include<Ogre.h>
#include<OIS.h>
#include<CEGUIMain.h>

class OISFramelistener : public Ogre::FrameListener, public OIS::KeyListener, public OIS::MouseListener, public Ogre::WindowEventListener
{
public:

    CEGUIMain* GUI;
    Ogre::RenderWindow* mWindow;
    OIS::Keyboard* mKeyboard;
    OIS::Mouse* mMouse;
    bool Shutdown;
    OISFramelistener(Ogre::RenderWindow* Window, OIS::Keyboard* Keyboard, OIS::Mouse* Mouse);

    ~OISFramelistener(void);

    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

//-------------------------------------------------------------------------------------
    virtual bool keyPressed( const OIS::KeyEvent &arg );

//-------------------------------------------------------------------------------------
    virtual bool keyReleased( const OIS::KeyEvent &arg );
//-------------------------------------------------------------------------------------
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
//-------------------------------------------------------------------------------------
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
//-------------------------------------------------------------------------------------
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
};

#endif