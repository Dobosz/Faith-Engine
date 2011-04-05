
/********************************************************
*                   FAITH ENGINE 2011                   *
*                                                       *
*                     Marcin Dobosz                     *
*                  Bratumi³ Rynkiewicz                  *
*                    Micha³ Kwestarz                    *
*                                                       *
*********************************************************/


// Ogre main lib
#include <Ogre.h>
// adicional window lib (WinAPI), used for ShowMessage function.
#include <windows.h>
// Using Ogre class as namespace, linking to other class will be do manualy. Brat do std odnosisz sie np. "std::cout", za to do klasy Ogra odnosimy sie bezsposrednio.
#include <GameEngine.h>
// Nasza klasa samej gry. Nie zawiera mechaniki, ale loopa renderowania.
using namespace Ogre;

//Kod zaklada, ze jedziemy na WIN32. Podstawowa bledow i takie tam.
#if OGRE_PLATFORM == PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char **argv) //ta funkcja main wykona sie jak nie jedziemy na WIN32, ale jedziemy.
#endif
{
    //Tworzy klase GameEngine
    try
    {
        GameEngine::getEngine()->Start();
    }
    catch(Exception& e) //Prosta obsluga bledow
    {
#if OGRE_PLATFORM == PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WIN32
        MessageBoxA(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        fprintf(stderr, "An exception has occurred: %s\n",
            e.getFullDescription().c_str());
#endif
    }

    return 0;
}