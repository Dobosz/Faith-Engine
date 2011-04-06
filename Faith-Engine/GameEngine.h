
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
    int ZOrderVP;
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
<<<<<<< .mine
    SceneNode* addViewPort(Ogre::Vector3);
    SceneNode* addViewPort(Ogre::Vector3, ColourValue);
    SceneNode* addViewPort(Ogre::Vector3, Ogre::Vector3);
    SceneNode* addViewPort(Ogre::Vector3, Ogre::Vector3, ColourValue);

=======    SceneNode* addViewPoint(Ogre::Vector3 move, Ogre::Vector3 = Ogre::Vector3(0,0,0), ColourValue = ColourValue(0,0,0));
>>>>>>> .theirsprivate:
    static GameEngine* pinstance; // Singleton instance
};

#define sGameEngine GameEngine::getEngine()

#endif