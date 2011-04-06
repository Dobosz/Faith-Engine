
#ifndef _CEGUIMain_H__
#define _CEGUIMain_H__

#include <CEGUI.h>
#include <RendererModules/Ogre/CEGUIOgreRenderer.h>

class CEGUIMain
{
protected:
	OgreRenderer* mRenderer;
public:
	CEGUIMain(void);

	~CEGUIMain(void);

void initialize();

static CEGUI::MouseButton convertButton(OIS::MouseButtonID buttonID)
{
    switch (buttonID)
    {
    case OIS::MB_Left:
        return CEGUI::LeftButton;
 
    case OIS::MB_Right:
        return CEGUI::RightButton;
 
    case OIS::MB_Middle:
        return CEGUI::MiddleButton;
 
    default:
        return CEGUI::LeftButton;
    }
}
};

#endif
