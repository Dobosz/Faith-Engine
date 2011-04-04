
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
    //Ta Funkcja jest funkcja która odpala ca³¹ reszte rzeczy potrzebnych do stworzenia sceny Ogra.
    createRoot();
    defineResources();
    setupRenderSystem();
    createRenderWindow();
    initializeResourceGroups();
    setupGUI();
    setupScene();
    setupInputSystem();
    createFrameListener();
    startRenderLoop();
}

void GameEngine::defineResources()
{
    //Napisa³em to funkcje ju¿ downo temu (chyba ja, ale nie jestem pewien na 100% :D). Odczytuje ona z pliku resources.cfg co ma za³adowaæ silnik. O szczegoly wypataj mnie.
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