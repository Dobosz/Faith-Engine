#include <precompiled.h>
#include <MainListener.h>
#include <NxOgreMain.h>

NxOgreMain::NxOgreMain(void)
    {
        //Tworzy úwiat
        mWorld = NxOgre::World::createWorld();

        //"Opis úwiata" - przyciπganie itp.
        NxOgre::SceneDescription sceneDesc;
        sceneDesc.mGravity = NxOgre::Vec3(0, -9.8f, 0);
        sceneDesc.mName = "The World";
        
        //Przypisanie "Opisu" do samego úwiata.
        mScene = mWorld->createScene(sceneDesc);

        //Domyúlny matera≥ fizyki (0).
        mScene->getMaterial(0)->setStaticFriction(0.5);
        mScene->getMaterial(0)->setDynamicFriction(0.5);
        mScene->getMaterial(0)->setRestitution(0.1);

        //Tworzy system renderowania fizyki. To nie jest konieczne. Fizyka moøe dzia≥aÅEi siÅEnie renderowaÅE
        mRenderSystem = new OGRE3DRenderSystem(mScene);
        mTime = NxOgre::TimeController::getSingleton();
    }