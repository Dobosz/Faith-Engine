#include<Ogre.h>
#include<OIS.h>
#include<CEGUIMain.h>

#pragma once
class OISFramelistener : public Ogre::FrameListener, public OIS::KeyListener, public OIS::MouseListener, public Ogre::WindowEventListener
{
public:

	CEGUIMain* GUI;
	Ogre::RenderWindow* mWindow;
	OIS::Keyboard* mKeyboard;
	OIS::Mouse* mMouse;
	bool Shutdown;
	OISFramelistener(Ogre::RenderWindow* Window, OIS::Keyboard* Keyboard, OIS::Mouse* Mouse)
	{
		Shutdown = true;
		mWindow = Window;
		mKeyboard = Keyboard;
		mMouse = Mouse;
		Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);
		mKeyboard->setEventCallback(this);
        mMouse->setEventCallback(this);
	}

	~OISFramelistener(void)
	{
	}
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt)
	{
		mMouse->capture();
		mKeyboard->capture();
		if (mWindow->isClosed()) return false;
		return Shutdown;
	} 
//-------------------------------------------------------------------------------------
	virtual bool keyPressed( const OIS::KeyEvent &arg )
	{

		CEGUI::System &sys = CEGUI::System::getSingleton();
		sys.injectKeyDown(arg.key);
		sys.injectChar(arg.text);

		switch (arg.key)
		{
		case OIS::KC_ESCAPE: 
			Shutdown = false;
        break;
		default:
        break;
    }
    return true;
	}
//-------------------------------------------------------------------------------------
	virtual bool keyReleased( const OIS::KeyEvent &arg )
	{
		CEGUI::System::getSingleton().injectKeyUp(arg.key);
		return true;
	}
//-------------------------------------------------------------------------------------
	virtual bool mouseMoved( const OIS::MouseEvent &arg )
	{
		CEGUI::System &sys = CEGUI::System::getSingleton();
		sys.injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
		// Scroll wheel.
		if (arg.state.Z.rel)
			sys.injectMouseWheelChange(arg.state.Z.rel / 120.0f);
		return true;
	}
//-------------------------------------------------------------------------------------
	virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
	{
		CEGUI::System::getSingleton().injectMouseButtonDown(CEGUIMain::convertButton(id));
		return true;
	}
//-------------------------------------------------------------------------------------
	virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
	{
		CEGUI::System::getSingleton().injectMouseButtonUp(CEGUIMain::convertButton(id));
		return true;
	}
};

