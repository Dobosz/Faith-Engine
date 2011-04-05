
#ifndef _GameEngine_H__
#define _GameEngine_H__

#include <Ogre.h>
#include <MainListener.h>

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

private:
    static GameEngine* pinstance; // Singleton instance
};

#endif