
#ifndef _GameEngine_H__
#define _GameEngine_H__

#include <precompiled.h>
#include <MainListener.h>
#include <OISMain.h>
#include <CEGUIMain.h>
#include <OISFramelistener.h>
#include <FreeCamOISListener.h>
#include <NxOgreMain.h>
#include <PhysicListener.h>

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
    // TODO: Move all classes to private part and make get functions...

    AnimationBlender * AnimNinja; //test animation blending

    SceneManager *mSceneMgr; //Menadzer sceny, to przez niego umieszczasz elmenty na scenie. Jest public, bo nie wiem jeszcze czy cos tam nie bedzie chcialo sie do nigo odwolac.
    Camera* mCamera;
    SceneNode* mCamNode;
    RenderWindow* mWindow;
    MainListener* mMainListener;
    OISFramelistener* mOISFramelistener;
    FreeCamOISListener* mFreeCamOISListener;
    OISMain* OIS;
    CEGUIMain* GUI;
    NxOgreMain* mPhysic;
    // Singleton of GameEngine
    static GameEngine* getEngine();

    void setupPhysic();
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
    FrameListener * createFrameListener(FrameListener*);
    void startRenderLoop();

    //Function which are not call on startup.
    void Scene();
    SceneNode * addView(Vector3, Vector3 look = Vector3(0,0,0));
    AnimationState * CreateBasicNodeAnim(Ogre::String name, Ogre::Real duration, SceneNode * snode, Vector3 VectorArray[], int NrKeyFrames, Quaternion RotArray[] = new Ogre::Quaternion[], bool loop = true);
    void RegisterAnimation(AnimationState * animation);
    void RegisterBlendedAnimation(AnimationBlender * animation);
    void CamJump(SceneNode*);
    SceneNode * addObject(Vector3, Ogre::String, Ogre::String, Vector3 scale = Vector3(1,1,1));
    Light * addLight(Vector3, ColourValue color = ColourValue(1,1,1));

    static GameEngine* pinstance; // Singleton instance
};

#endif