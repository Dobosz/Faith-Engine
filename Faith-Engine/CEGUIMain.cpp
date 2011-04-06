
#include <CEGUIMain.h>
#include <OgreCEGUIRenderer.h>

CEGUIMain::CEGUIMain(void)
{
}

CEGUIMain::~CEGUIMain(void)
{
}

void CEGUIMain::initialize()
{
    /*
    mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
    CEGUI::Imageset::setDefaultResourceGroup("Imagesets");
    CEGUI::Font::setDefaultResourceGroup("Fonts");
    CEGUI::Scheme::setDefaultResourceGroup("Schemes");
    CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
    CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
    CEGUI::SchemeManager::getSingleton().create("WindowsLook.scheme");
    CEGUI::System::getSingleton().setDefaultMouseCursor("WindowsLook", "MouseArrow");
    CEGUI::MouseCursor::getSingleton().setImage( CEGUI::System::getSingleton().getDefaultMouseCursor());
    */
    // Initialisation Area
    CEGUI::OgreCEGUIRenderer* mGUIRenderer = new CEGUI::OgreCEGUIRenderer(Root::getSingleton().getAutoCreatedWindow(), Ogre::RENDER_QUEUE_OVERLAY, false, 3000);
    CEGUI::System* mGUISystem = new CEGUI::System(mGUIRenderer);
    CEGUI::Logger::getSingleton().setLoggingLevel(CEGUI::Informative); // this is recommended to help with debugging, but not neccessary
 
    CEGUI::SchemeManager::getSingleton().loadScheme((CEGUI::utf8*)"TaharezLook.scheme");
    mGUISystem->setDefaultMouseCursor((CEGUI::utf8*)"TaharezLook", (CEGUI::utf8*)"MouseArrow");
    CEGUI::Window* mRootWindow= CEGUI::WindowManager::getSingleton().createWindow((CEGUI::utf8*)"DefaultWindow", (CEGUI::utf8*)"RootWindow");  
    mGUISystem->setGUISheet(mRootWindow); // set active Window
}

