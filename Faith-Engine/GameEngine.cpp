
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
    delete mMainListener;
}

// Signeton structure
GameEngine* GameEngine::pinstance(0);

GameEngine* GameEngine::getEngine()
{
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
    setupScene();
    setupCamera();
    Scene();
    createFrameListener();
    setupGUI();
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
    mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "Default SceneManager"); //Inicjalizacja menadzera sceny.
    mSceneMgr->setAmbientLight(ColourValue(0.5,0.5,0.5));
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
    addObject(Vector3(0,0,0),"ogrehead", Vector3(0.7,0.7,0.7));
    //Swiatlo punktowe.
    addLight(Vector3(20,80,50));
    CamJump(addView(Vector3(100,100,100)));
        /*      PRZYKLADOWA SCENA   KONIEC      */
}

void GameEngine::setupInputSystem()
{
    //Obsluga klawiatury i myszki. Bedziemy uzywac bibliotek OIS, ale to innym razem.
    OIS = new OISMain();
    OIS->Initialize(mWindow);
}

void GameEngine::createFrameListener()
{
    //Tu deklaruje sie Listenery, to takie watki dla glownego loopa grafiki. Przykladay pokarze ci potem.
    mMainListener = new MainListener();
    mRoot->addFrameListener(mMainListener);
    mOISFramelistener = new OISFramelistener(mWindow, OIS->mKeyboard, OIS->mMouse);
    mRoot->addFrameListener(mOISFramelistener);

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

SceneNode * GameEngine::addObject(Vector3 pos, Ogre::String name, Vector3 scale)
{
    Ogre::Entity* e = mSceneMgr->createEntity(name, name+".mesh");
    SceneNode* n = mSceneMgr->getRootSceneNode()->createChildSceneNode(name+"Node");
    n->attachObject(e);
    n->setPosition(pos);
    n->setScale(scale);
    return n;
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
