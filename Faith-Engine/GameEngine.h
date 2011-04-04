#pragma once
#include <Ogre.h>

using namespace Ogre;

class GameEngine
{
protected:
    Root *mRoot; //Główny korzeń silnika graficznego. Inicjalizacja następuje w funkcji createRoot().
public:
    SceneManager *mSceneMgr; //Menadzer sceny, to przez niego umieszczasz elmenty na scenie. Jest public, bo nie wiem jeszcze czy coś tam nie będzie chciało sie do nigo odwołać.

    GameEngine(void)
    {
    }

    ~GameEngine(void)
    {
    }

    void go()
    {
        //Ta Funkcja jest funkcja która odpala całą reszte rzeczy potrzebnych do stworzenia sceny Ogra.
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

    void createRoot()
    {
        mRoot = new Root(); //Tworzenie rdzenia, korzenia silnika graficznego.
    }

    void defineResources()
    {
        //Napisałem to funkcje już downo temu (chyba ja, ale nie jestem pewien na 100% :D). Odczytuje ona z pliku resources.cfg co ma załadować silnik. O szczeguły wypataj mnie.
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

    void setupRenderSystem()
    {
        //Dobra to coś pozwala ci na wybór czy renderujesz obraz w DirectX'ie czy w OpenGL'u. Rozdzielczość i takie tam.
        //Jak plik Ogre.cfg istnieje i można go odczytać to odpala konfigi z niego jak nie to opdala dialogboxa z opcjami konfiguracji.
        if (!mRoot->restoreConfig() && !mRoot->showConfigDialog())
            throw Exception(52, "User canceled the config dialog!", "Application::setupRenderSystem()");//Jak waszystko sie posypie to wywala błąd :P.
    }

    void createRenderWindow()
    {
        //Tworzy okienko w WinApi.
        mRoot->initialise(true, "Faith Engine"); // "Faith Engine" - to nazwa okna pod Win32.
    }

    void initializeResourceGroups()
    {
        TextureManager::getSingleton().setDefaultNumMipmaps(5); //Dotyczy techniki wyśfietlania tekstur. Nie ruszeaj tego. Jak chcesz wiedzieć wiecej to zapytaj, albo google.
        ResourceGroupManager::getSingleton().initialiseAllResourceGroups(); //Ładuje wszystkie resoursy przeczytane z defineResources().
    }

    void setupGUI()
    {
        //Na razie nie ma GUI ale bedzie trzeba zrobić implementacje jego w przyszłości. Czytaj w specyfikacji.
    }

    void setupScene()
    {
        mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "Default SceneManager"); //Inicjalizacja menadzera sceny.
    }

    void setupInputSystem()
    {
        //Obsługa klawiatury i myszki. Bedziemy używać bibliotek OIS, ale to innym razem.
    }

    void createFrameListener()
    {
        //Tu deklaruje sie Listenery, to takie watki dla głównego loopa grafiki. Przykładay pokarze ci potem.
    }

    void startRenderLoop()
    {
        mRoot->startRendering(); //Odpala główna pętle renderowania sceny.
    }
};