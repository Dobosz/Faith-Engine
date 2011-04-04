/*********************************************************
*                     FAITH ENGINE 2011                   *
*                                                                      *
*                         Marcin Dobosz                       *
*                   Bart�omiej Rinkiewicz                  *
*                       Micha� Kwestarz                     *
*                                                                      *
*********************************************************/

//PROJEKT ZAK�ADA, �E MASZ OGRA SDK NA C:\Ogre SDK 1.7.1\. JAK JEST INACZEJ TO ZMIEN TO W PROJEKCIE ALBO LEPIEJ ZR�B TAK JAK JA MAM BO BEDZIESZ ROBI� SYF (!).
//Dysk X ustaw sobie folder gdzie masz repo.

// Ogre main lib
#include <Ogre.h>
// adicional window lib (WinAPI), used for ShowMessage function.
#include <windows.h>
// Using Ogre class as namespace, linking to other class will be do manualy. Brat do std odnosisz sie np. "std::cout", za to do klasy Ogra odnosimy sie bespo�rednio.
#include <GameEngine.h>
// Nasza klasa samej gry. Nie zawiera mechaniki, ale loopa renderowania.
using namespace Ogre;

//Kod zak�ada, �e jedziemy na WIN32. Podstawowa obs�uga b��d�w i takie tam.
#if OGRE_PLATFORM == PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
int main(int argc, char **argv) //ta funkcja main wykona si� jak nie jedziemy na WIN32, ale jedziemy.
#endif
{
//Tworzy klase GameEngine
    try
    {
        GameEngine Engine;
        Engine.go();
    }
    catch(Exception& e) //Prosta obs�uga b��d�w.
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