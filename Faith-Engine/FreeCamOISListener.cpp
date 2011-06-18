
#include <precompiled.h>
#include <FreeCamOISListener.h>
#include <GameEngine.h> //only for blender animation test

FreeCamOISListener::FreeCamOISListener(Ogre::RenderWindow* Window, OIS::Keyboard* Keyboard, OIS::Mouse* Mouse, Ogre::SceneNode* CamNode)
{
    Shutdown = true;
    mWindow = Window;
    mKeyboard = Keyboard;
    mMouse = Mouse;
    mCamNode = CamNode;

    // Rotacja i ruch
    mRotate = 0.13;
    mMove = 250;

    mDirection = Ogre::Vector3::ZERO;

    Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);
    mKeyboard->setEventCallback(this);
    mMouse->setEventCallback(this);
}

FreeCamOISListener::~FreeCamOISListener(void)
{
}

bool FreeCamOISListener::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    mMouse->capture();
    mKeyboard->capture();
    mCamNode->translate(mDirection * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
    if (mWindow->isClosed()) return false;
        return Shutdown;
}
//-------------------------------------------------------------------------------------
bool FreeCamOISListener::keyPressed( const OIS::KeyEvent &arg )
{
    sCEGUI().injectKeyDown(arg.key);
    sCEGUI().injectChar(arg.text);

    switch(arg.key)
    {
        case OIS::KC_TAB: sGameEngine->AnimNinja->blend("Walk", AnimationBlender::BlendWhileAnimating, 0.2, true ); break; //Animation blender test
        case OIS::KC_ESCAPE:
            Shutdown = false;
        break;
        case OIS::KC_UP:
        case OIS::KC_W:
            mDirection.z = -mMove;
        break;

        case OIS::KC_DOWN:
        case OIS::KC_S:
            mDirection.z = mMove;
        break;

        case OIS::KC_LEFT:
        case OIS::KC_A:
            mDirection.x = -mMove;
        break;

        case OIS::KC_RIGHT:
        case OIS::KC_D:
            mDirection.x = mMove;
        break;

        case OIS::KC_PGDOWN:
        case OIS::KC_E:
            mDirection.y = -mMove;
        break;

        case OIS::KC_PGUP:
        case OIS::KC_Q:
        case OIS::KC_SPACE:
            mDirection.y = mMove;
        break;
    }

    return true;
}
//-------------------------------------------------------------------------------------
bool FreeCamOISListener::keyReleased( const OIS::KeyEvent &arg )
{
    sCEGUI().injectKeyUp(arg.key);

    switch (arg.key)
    {
        case OIS::KC_TAB: sGameEngine->AnimNinja->blend("Idle1", AnimationBlender::BlendWhileAnimating, 0.2, true ); break; //Animation blender test
        case OIS::KC_UP:
        case OIS::KC_W:
             mDirection.z = 0;
        break;

        case OIS::KC_DOWN:
        case OIS::KC_S:
             mDirection.z = 0;
           break;

        case OIS::KC_LEFT:
        case OIS::KC_A:
              mDirection.x = 0;
        break;

        case OIS::KC_RIGHT:
        case OIS::KC_D:
               mDirection.x = 0;
        break;

        case OIS::KC_PGDOWN:
        case OIS::KC_E:
                mDirection.y = 0;
        break;

        case OIS::KC_PGUP:
        case OIS::KC_Q:
        case OIS::KC_SPACE:
                mDirection.y = 0;
        break;

        default:    break;
    }
    return true;
}
//-------------------------------------------------------------------------------------
bool FreeCamOISListener::mouseMoved( const OIS::MouseEvent &arg )
{
    CEGUI::System &sys = sCEGUI();
    sys.injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
    // Scroll wheel.
    if (arg.state.Z.rel)
        sys.injectMouseWheelChange(arg.state.Z.rel / 120.0f);

    if(arg.state.buttonDown(OIS::MB_Right))
    {
        mCamNode->yaw(Ogre::Degree(-mRotate * arg.state.X.rel), Ogre::Node::TS_WORLD);
        mCamNode->pitch(Ogre::Degree(-mRotate * arg.state.Y.rel), Ogre::Node::TS_LOCAL);
        CEGUI::MouseCursor::getSingleton().setImage("WindowsLook","MouseMoveCursor");
    }
    else
        CEGUI::MouseCursor::getSingleton().setImage( sCEGUI().getDefaultMouseCursor());

    return true;
}
//-------------------------------------------------------------------------------------
bool FreeCamOISListener::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    sCEGUI().injectMouseButtonDown(CEGUIMain::convertButton(id));

    return true;
}
//-------------------------------------------------------------------------------------
bool FreeCamOISListener::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
    sCEGUI().injectMouseButtonUp(CEGUIMain::convertButton(id));
    CEGUI::MouseCursor::getSingleton().setImage( sCEGUI().getDefaultMouseCursor());
    return true;
}
