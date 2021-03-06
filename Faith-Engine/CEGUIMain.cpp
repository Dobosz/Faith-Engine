
#include <precompiled.h>
#include <CEGUIMain.h>

CEGUIMain::CEGUIMain()
{
}

CEGUIMain::~CEGUIMain()
{
}

void CEGUIMain::initialize()
{
    mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
    CEGUI::Imageset::setDefaultResourceGroup("Imagesets");
    CEGUI::Font::setDefaultResourceGroup("Fonts");
    CEGUI::Scheme::setDefaultResourceGroup("Schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
    CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
    CEGUI::SchemeManager::getSingleton().create("WindowsLook.scheme");
    sCEGUI().setDefaultMouseCursor("WindowsLook", "MouseArrow");
    CEGUI::MouseCursor::getSingleton().setImage( sCEGUI().getDefaultMouseCursor());
}
