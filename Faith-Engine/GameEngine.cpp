
#include <GameEngine.h>

GameEngine::GameEngine()
{
    // Constructor, Initialize empty variables.
    mRoot = NULL;
}

GameEngine::~GameEngine()
{
    // Free memory and stuff

    // Do we need to remove mRoot ? GameEngine will be initialized only once so killing it means whole game close
    if (mRoot)
        delete mRoot;
}

void GameEngine::Start()
{
    //Ta Funkcja jest funkcja kt�ra odpala ca�� reszte rzeczy potrzebnych do stworzenia sceny Ogra.
    createRoot();
    defineResources();
    setupRenderSystem();
    createRenderWindow();
    initializeResourceGroups();
    setupGUI();
    setupScene();
	setupCamera();
    setupInputSystem();
    createFrameListener();
    startRenderLoop();
}

void GameEngine::setupCamera()
{
	//Tworzy kamere. U�ywamy tylko jednej kamery. Prze�aczamy ja viewpointami.
	mCamera = mSceneMgr->createCamera("Camera");
	//Node do kamery. Nim obracasz kamere. Nie rob tego tylko ciagnij zawsze za vp.
	mCamNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("CamNode");
	//przylaczanie kamery do noda
	mCamNode->attachObject(mCamera);
	//ustawienie kamery na pozycje 0,0,80 GLOBAL.
	mCamNode->setPosition(Ogre::Vector3(0,0,80));
	//Kamera patrzy na PUNKT 0,0,0 GLOBAL.
	mCamera->lookAt(Ogre::Vector3(0,0,0));
	//Ustawia kiedy obiekt ma sta� si� niewidzialny bo kamera jest za daleko lub zablisko.
	mCamera->setNearClipDistance(5);
	//tworzenie punktu widokowego. Mo�e by� ich kilka.
	Viewport* vp = mWindow->addViewport(mCamera);
	//ustawia kolor t�a jeszcze przed renderem sceny.
	vp->setBackgroundColour(ColourValue(0,0,0));
	//Dostosowuje kamere do rodzaju ekranu (4:3, 16:9, 16:10). Troche matmy :D.
	mCamera->setAspectRatio(Real(vp->getActualHeight()) / Real(vp->getActualHeight()));
}

void GameEngine::defineResources()
{
    //Napisa�em to funkcje ju� downo temu (chyba ja, ale nie jestem pewien na 100% :D). Odczytuje ona z pliku resources.cfg co ma za�adowa� silnik. O szczegoly wypataj mnie.
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