#pragma once
#include <Ogre.h>

using namespace Ogre;

class GameEngine
{
protected:
    Root *mRoot; //G��wny korze� silnika graficznego. Inicjalizacja nast�puje w funkcji createRoot().
public:
    SceneManager *mSceneMgr; //Menadzer sceny, to przez niego umieszczasz elmenty na scenie. Jest public, bo nie wiem jeszcze czy co� tam nie b�dzie chcia�o sie do nigo odwo�a�.

    GameEngine(void)
    {
    }

    ~GameEngine(void)
    {
    }

    void go()
    {
        //Ta Funkcja jest funkcja kt�ra odpala ca�� reszte rzeczy potrzebnych do stworzenia sceny Ogra.
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
        //Napisa�em to funkcje ju� downo temu (chyba ja, ale nie jestem pewien na 100% :D). Odczytuje ona z pliku resources.cfg co ma za�adowa� silnik. O szczegu�y wypataj mnie.
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
        //Dobra to co� pozwala ci na wyb�r czy renderujesz obraz w DirectX'ie czy w OpenGL'u. Rozdzielczo�� i takie tam.
        //Jak plik Ogre.cfg istnieje i mo�na go odczyta� to odpala konfigi z niego jak nie to opdala dialogboxa z opcjami konfiguracji.
        if (!mRoot->restoreConfig() && !mRoot->showConfigDialog())
            throw Exception(52, "User canceled the config dialog!", "Application::setupRenderSystem()");//Jak waszystko sie posypie to wywala b��d :P.
    }

    void createRenderWindow()
    {
        //Tworzy okienko w WinApi.
        mRoot->initialise(true, "Faith Engine"); // "Faith Engine" - to nazwa okna pod Win32.
    }

    void initializeResourceGroups()
    {
        TextureManager::getSingleton().setDefaultNumMipmaps(5); //Dotyczy techniki wy�fietlania tekstur. Nie ruszeaj tego. Jak chcesz wiedzie� wiecej to zapytaj, albo google.
        ResourceGroupManager::getSingleton().initialiseAllResourceGroups(); //�aduje wszystkie resoursy przeczytane z defineResources().
    }

    void setupGUI()
    {
        //Na razie nie ma GUI ale bedzie trzeba zrobi� implementacje jego w przysz�o�ci. Czytaj w specyfikacji.
    }

    void setupScene()
    {
        mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "Default SceneManager"); //Inicjalizacja menadzera sceny.
    }

    void setupInputSystem()
    {
        //Obs�uga klawiatury i myszki. Bedziemy u�ywa� bibliotek OIS, ale to innym razem.
    }

    void createFrameListener()
    {
        //Tu deklaruje sie Listenery, to takie watki dla g��wnego loopa grafiki. Przyk�aday pokarze ci potem.
    }

    void startRenderLoop()
    {
        mRoot->startRendering(); //Odpala g��wna p�tle renderowania sceny.
    }
};