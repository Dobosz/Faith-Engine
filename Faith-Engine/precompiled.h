
#ifndef FE_PRECOMPILED_H
#define FE_PRECOMPILED_H

#ifdef WIN32
    #include <windows.h>
#endif

#include <Ogre.h> // Ogre main lib
#include <OIS.h> // Input System
#include <CEGUI.h> // GUI lib
#include <RendererModules/Ogre/CEGUIOgreRenderer.h> // Additional rendering for GUI
#define sGameEngine GameEngine::getEngine()
#endif