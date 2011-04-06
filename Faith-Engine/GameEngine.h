
#ifndef _GameEngine_H__
#define _GameEngine_H__

#include <MainListener.h>
#include <OISMain.h>
#include <CEGUIMain.h>
#include <OISFramelistener.h>

using namespace Ogre;

class GameEngine
{
protected:
    Root *mRoot; //Glowny korzen silnika graficznego. Inicjalizacja nastepuje w funkcji createRoot().

    // Constructor
    GameEngine();
    GameEngine(const GameEngine&);
    GameEngine& operator= (const GameEngine&);
    // Destructor
    ~GameEngine();

public:
    SceneManager *mSceneMgr; //Menadzer sceny, to przez niego umieszczasz elmenty na scenie. Jest public, bo nie wiem jeszcze czy cos tam nie bedzie chcialo sie do nigo odwolac.
    Camera* mCamera;
    SceneNode* mCamNode;
    RenderWindow* mWindow;
    MainListener* mMainListener;
    OISFramelistener* mOISFramelistener;
    OISMain* OIS;
    CEGUIMain* GUI;
    // Singleton
    static GameEngine* getEngine();

    void defineResources();
    void setupCamera();
    void Start();
    void createRoot();
    void setupRenderSystem();
    void createRenderWindow();
    void initializeResourceGroups();
    void setupGUI();
    void setupScene();
    void setupInputSystem();
    void createFrameListener();
    void startRenderLoop();

    //Function which are not call on startup.
    void Scene();
    SceneNode * addView(Vector3, Vector3 look = Vector3(0,0,0));
    void CamJump(SceneNode*);
    SceneNode * addObject(Vector3, Ogre::String, Vector3 scale = Vector3(1,1,1));
    static GameEngine* pinstance; // Singleton instance
};

#define sGameEngine GameEngine::getEngine()

#endif