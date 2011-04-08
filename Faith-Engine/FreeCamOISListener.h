
#ifndef _FreeCamOISListener_H__
#define _FreeCamOISListener_H__

#include <precompiled.h>
#include <CEGUIMain.h>

class FreeCamOISListener : public Ogre::FrameListener, public OIS::KeyListener, public OIS::MouseListener, public Ogre::WindowEventListener
{
public:
    Ogre::RenderWindow* mWindow;
    OIS::Keyboard* mKeyboard;
    OIS::Mouse* mMouse;
    Ogre::SceneNode* mCamNode;
    Ogre::Vector3 mDirection;
    Ogre::Real mRotate;
    Ogre::Real mMove;
    bool Shutdown;

    FreeCamOISListener(Ogre::RenderWindow* Window, OIS::Keyboard* Keyboard, OIS::Mouse* Mouse, Ogre::SceneNode* CamNode);

    ~FreeCamOISListener(void);

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
