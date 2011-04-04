
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <Ogre.h>

using namespace Ogre;

class GameEngine
{
protected:
    Root *mRoot; //G³ówny korzeñ silnika graficznego. Inicjalizacja nastêpuje w funkcji createRoot().
public:
    SceneManager *mSceneMgr; //Menadzer sceny, to przez niego umieszczasz elmenty na scenie. Jest public, bo nie wiem jeszcze czy coœ tam nie bêdzie chcia³o sie do nigo odwo³aæ.

    // Constructor
    GameEngine();
    // Destructor
    ~GameEngine();

    void defineResources();

    void Start();

    void createRoot()
    {
        mRoot = new Root(); //Tworzenie rdzenia, korzenia silnika graficznego.
    }

    void setupRenderSystem()
    {
        //Dobra to coœ pozwala ci na wybór czy renderujesz obraz w DirectX'ie czy w OpenGL'u. Rozdzielczoœæ i takie tam.
        //Jak plik Ogre.cfg istnieje i mo¿na go odczytaæ to odpala konfigi z niego jak nie to opdala dialogboxa z opcjami konfiguracji.
        if (!mRoot->restoreConfig() && !mRoot->showConfigDialog())
            throw Exception(52, "User canceled the config dialog!", "Application::setupRenderSystem()");//Jak waszystko sie posypie to wywala b³¹d :P.
    }

    void createRenderWindow()
    {
        //Tworzy okienko w WinApi.
        mRoot->initialise(true, "Faith Engine"); // "Faith Engine" - to nazwa okna pod Win32.
    }

    void initializeResourceGroups()
    {
        TextureManager::getSingleton().setDefaultNumMipmaps(5); //Dotyczy techniki wyœfietlania tekstur. Nie ruszeaj tego. Jak chcesz wiedzieæ wiecej to zapytaj, albo google.
        ResourceGroupManager::getSingleton().initialiseAllResourceGroups(); //£aduje wszystkie resoursy przeczytane z defineResources().
    }

    void setupGUI()
    {
        //Na razie nie ma GUI ale bedzie trzeba zrobiæ implementacje jego w przysz³oœci. Czytaj w specyfikacji.
    }

    void setupScene()
    {
        mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "Default SceneManager"); //Inicjalizacja menadzera sceny.
    }

    void setupInputSystem()
    {
        //Obs³uga klawiatury i myszki. Bedziemy u¿ywaæ bibliotek OIS, ale to innym razem.
    }

    void createFrameListener()
    {
        //Tu deklaruje sie Listenery, to takie watki dla g³ównego loopa grafiki. Przyk³aday pokarze ci potem.
    }

    void startRenderLoop()
    {
        mRoot->startRendering(); //Odpala g³ówna pêtle renderowania sceny.
    }
};