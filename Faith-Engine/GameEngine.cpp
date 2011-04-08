
#include <precompiled.h>
#include <GameEngine.h>

GameEngine::GameEngine()
{
    // Constructor, Initialize empty variables.
    mRoot = NULL;
    mWindow = NULL;
    mCamera = NULL;
}

GameEngine::~GameEngine()
{
    // Free memory and stuff

    // Do we need to remove mRoot ? GameEngine will be initialized only once so killing it means whole game close
    if (mRoot)
        delete mRoot;
    //this will close the game on GameEngine delete.
    if (mMainListener)
        delete mMainListener;

    if (mOISFramelistener)
        delete mOISFramelistener;
}

// Signeton structure
GameEngine* GameEngine::pinstance(0);

GameEngine* GameEngine::getEngine()
{
    // Singleton, if not initialized yet, make new one and return.
    return (pinstance != NULL ? pinstance : (pinstance =new GameEngine()));
}

void GameEngine::Start()
{
    //Ta Funkcja jest funkcja ktora odpala cala reszte rzeczy potrzebnych do stworzenia sceny Ogra.
    createRoot();
    defineResources();
    setupRenderSystem();
    createRenderWindow();
    initializeResourceGroups();
    setupInputSystem();
    setupGUI();
    setupScene();
    setupCamera();
    mMainListener = static_cast<MainListener *>(createFrameListener (new MainListener())); 
    Scene();
    mOISFramelistener = static_cast<OISFramelistener *>(createFrameListener (new OISFramelistener(mWindow, OIS->mKeyboard, OIS->mMouse)));
    mFreeCamOISListener = static_cast<FreeCamOISListener *>(createFrameListener (new FreeCamOISListener(mWindow, OIS->mKeyboard, OIS->mMouse, mCamNode)));
    startRenderLoop();
}

Light * GameEngine::addLight(Vector3 pos, ColourValue color)
{
    Light * l = mSceneMgr->createLight();
    l->setPosition(pos);
    l->setCastShadows(true);
    l->setDiffuseColour(color);
    l->setSpecularColour(ColourValue(0.9,0.9,0.9));
    return l;
}

void GameEngine::createRoot()
{
    mRoot = new Root(); //Tworzenie rdzenia, korzenia silnika graficznego.
}

void GameEngine::setupRenderSystem()
{
    //Dobra to cos pozwala ci na wybor czy renderujesz obraz w DirectX'ie czy w OpenGL'u. Rozdzielczosc i takie tam.
    //Jak plik Ogre.cfg istnieje i mozna go odczytac to odpala konfigi z niego jak nie to opdala dialogboxa z opcjami konfiguracji.
    if (!mRoot->restoreConfig() && !mRoot->showConfigDialog())
        throw Exception(52, "User canceled the config dialog!", "Application::setupRenderSystem()");//Jak waszystko sie posypie to wywala blad :P.
}

void GameEngine::initializeResourceGroups()
{
    TextureManager::getSingleton().setDefaultNumMipmaps(5); //Dotyczy techniki wyswietlania tekstur. Nie ruszeaj tego. Jak chcesz wiedziec wiecej to zapytaj, albo google.
    ResourceGroupManager::getSingleton().initialiseAllResourceGroups(); //Laduje wszystkie resoursy przeczytane z defineResources().
}

void GameEngine::setupGUI()
{
    //Na razie nie ma GUI ale bedzie trzeba zrobic implementacje jego w przyszlosci. Czytaj w specyfikacji.
    GUI = new CEGUIMain();
    GUI->initialize();
}

void GameEngine::createRenderWindow()
{
    //Tworzy okienko w WinApi.
    mWindow = mRoot->initialise(true, "Faith Engine"); //"Faith Engine" - to nazwa okna pod Win32.
}

void GameEngine::setupScene()
{
    mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "SceneManager"); //Inicjalizacja menadzera sceny.
    mSceneMgr->setAmbientLight(ColourValue(0.5,0.5,0.5)); //Global lighting
    mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE); //Shadows
}

void GameEngine::setupCamera()
{
    //Tworzy kamere. Uzywamy tylko jednej kamery. Przelaczamy ja viewpointami.
    mCamera = mSceneMgr->createCamera("Camera");
    //Node do kamery. Nim obracasz kamere. Nie rob tego tylko ciagnij zawsze za vp.
    mCamNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("CamNode");
    //przylaczanie kamery do noda
    mCamNode->attachObject(mCamera);
    //ustawienie kamery na pozycje 0,0,80 GLOBAL.
    mCamNode->setPosition(Ogre::Vector3(0,0,80));
    //Kamera patrzy na PUNKT 0,0,0 GLOBAL.
    mCamera->lookAt(Ogre::Vector3(0,0,0));
    //Ustawia kiedy obiekt ma stac sie niewidzialny bo kamera jest za daleko lub zablisko.
    mCamera->setNearClipDistance(5);
    //tworzenie punktu widokowego. Moze byc ich kilka.
    Viewport* vp = mWindow->addViewport(mCamera);
    //ustawia kolor tla jeszcze przed renderem sceny.
    vp->setBackgroundColour(ColourValue(0,0,0));
    //Dostosowuje kamere do rodzaju ekranu (4:3, 16:9, 16:10). Troche matmy :D.
    mCamera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight()));
}
void GameEngine::Scene()
{
        /*      PRZYKLADOWA SCENA   POCZATEK    */
    //Swiatlo punktowe.
    addLight(Vector3(500,500,-500),ColourValue(0.0,0.7,0.7));
    addLight(Vector3(-0,500,500),ColourValue(0.2,0.2,0.9));
    CamJump(addView(Vector3(0,1000,1000),Vector3(0,50,0)));

    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
    Ogre::MeshManager::getSingleton().createPlane("ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane, 1500, 1500, 20, 20, true, 1, 12, 12, Ogre::Vector3::UNIT_Z);
    Ogre::Entity* entGround = mSceneMgr->createEntity("GroundEntity", "ground");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(entGround);
    entGround->setMaterialName("Examples/Rockwall");
    entGround->setCastShadows(false);

    SceneNode * object1 = addObject(Vector3(0,0,0),"ogrehead1", "ogrehead", Vector3(0.3,0.3,0.3));
    SceneNode * object2 = addObject(Vector3(0,0,0),"ogrehead2", "ogrehead", Vector3(0.4,0.4,0.4));
    SceneNode * object3 = addObject(Vector3(0,0,0),"ogrehead3", "ogrehead", Vector3(0.2,0.2,0.2));

    Vector3 vec1[] = {Vector3(200,464,464), Vector3(648,546,540), Vector3(-560,580,100), Vector3(-80,400,-568)};
    Vector3 vec2[] = {Vector3(400,80,560), Vector3(0,80,50), Vector3(-200,560,400), Vector3(200,400,-50)};
    Vector3 vec3[] = {Vector3(580,75,464), Vector3(0,464,50), Vector3(-580,464,0), Vector3(0,464, 0)};

    Ogre::Quaternion q1[]  = {Quaternion(48,-68,49,0), Quaternion(-90,0,-45,80), Quaternion(90,-68,40,50), Quaternion(-40,49,-80,86),};
    Ogre::Quaternion q2[]  = {Quaternion(48,68,50,0), Quaternion(60,0, 55,70), Quaternion(90,-68,90,86), Quaternion(-40,70,49, 80),};
    Ogre::Quaternion q3[]  = {Quaternion(86,-70,90,0), Quaternion(-90,0,-45,70), Quaternion(90,-70,40,68), Quaternion(-40,70,-49,86),};

    RegisterAnimation(CreateBasicNodeAnim("Animation1", 4.0, object1, vec1, 4, q1));
    RegisterAnimation(CreateBasicNodeAnim("Animation2", 4.0, object2, vec2, 4, q2));
    RegisterAnimation(CreateBasicNodeAnim("Animation3", 4.0, object3, vec3, 4, q3));

    //RegisterAnimation(CreateBasicNodeAnim("CamAnimation", 20.0, mCamNode, vec1, 4));
        /*      PRZYKLADOWA SCENA   KONIEC      */
}

void GameEngine::setupInputSystem()
{
    //Obsluga klawiatury i myszki. Bedziemy uzywac bibliotek OIS, ale to innym razem.
    OIS = new OISMain();
    OIS->Initialize(mWindow);
}

FrameListener * GameEngine::createFrameListener(Ogre::FrameListener * FL)
{
    //Tu deklaruje sie Listenery, to takie watki dla glownego loopa grafiki. Przykladay pokarze ci potem.
    mRoot->addFrameListener(FL);
    return FL;
}

void GameEngine::startRenderLoop()
{
    mRoot->startRendering(); //Odpala glowna petle renderowania sceny.
}

SceneNode * GameEngine::addView(Vector3 pos, Vector3 look)
{
    Ogre::SceneNode * vNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    vNode->setPosition(pos);
    vNode->lookAt(look, Node::TS_WORLD);
    return vNode;
}

void GameEngine::CamJump(SceneNode* view)
{
    mCamera->detachFromParent();
    mCamNode = view;
    mCamera->detachFromParent();
    mCamNode->attachObject(mCamera);
}

SceneNode * GameEngine::addObject(Vector3 pos, Ogre::String name, Ogre::String mesh, Vector3 scale)
{
    Ogre::Entity* e = mSceneMgr->createEntity(name, mesh+".mesh");
    e->setCastShadows(true);
    SceneNode* n = mSceneMgr->getRootSceneNode()->createChildSceneNode(name+"Node");
    n->attachObject(e);
    n->setPosition(pos);
    n->setScale(scale);
    return n;
}

AnimationState * GameEngine::CreateBasicNodeAnim(Ogre::String name, Ogre::Real duration, SceneNode * snode, Vector3 VectorArray[], int NrKeyFrames, Quaternion RotArray[], bool loop)
{
    Animation* animation = mSceneMgr->createAnimation(name, duration);
    animation->setInterpolationMode(Animation::IM_LINEAR);
    NodeAnimationTrack* track = animation->createNodeTrack(0, snode);
    track->setUseShortestRotationPath(true);
    Real step = duration/NrKeyFrames;

    TransformKeyFrame* key;

    for(int i = 0; i != NrKeyFrames; i++)
    {
    key = track->createNodeKeyFrame(step*i);
    key->setTranslate(VectorArray[i]);
    key->setRotation(RotArray[i]);
    }

    AnimationState * NodeAnimationState = mSceneMgr->createAnimationState(name);
    NodeAnimationState->setEnabled(true);
    NodeAnimationState->setLoop(loop);
    return NodeAnimationState;
}

void GameEngine::RegisterAnimation(AnimationState * animation)
{
    mMainListener->AnimationArray.insert(mMainListener->AnimationArray.end(), animation);
}

void GameEngine::defineResources()
{
    //Napisalem to funkcje juz downo temu (chyba ja, ale nie jestem pewien na 100% :D). Odczytuje ona z pliku resources.cfg co ma zaladowac silnik. O szczegoly wypataj mnie.
    String secName, typeName, archName;
    ConfigFile cf;
    cf.load("resources.cfg");
    ConfigFile::SectionIterator seci = cf.getSectionIterator();
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        ConfigFile::SettingsMultiMap *settings = seci.getNext();
        ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
        }
    }
}
