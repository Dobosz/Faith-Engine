#ifndef _GameEngine_H__
#define _GameEngine_H__

#include <Ogre.h>

using namespace Ogre;

class GameEngine
{
protected:
    Root *mRoot; //Glowny korzen silnika graficznego. Inicjalizacja nastepuje w funkcji createRoot().
    static GameEngine *Singleton = NULL;
public:
    SceneManager *mSceneMgr; //Menadzer sceny, to przez niego umieszczasz elmenty na scenie. Jest public, bo nie wiem jeszcze czy cos tam nie bedzie chcialo sie do nigo odwolac.
    Camera* mCamera;
    SceneNode* mCamNode;
    Ogre::RenderWindow* mWindow;

    // Constructor
    GameEngine();
    // Destructor
    ~GameEngine();

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
    static GameEngine* getSingleton();
};

#endif