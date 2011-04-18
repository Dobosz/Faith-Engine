#include <precompiled.h>
#include <MainListener.h>
#include <NxOgreMain.h>

NxOgreMain::NxOgreMain(void)
    {
        //Tworzy œwiat
        mWorld = NxOgre::World::createWorld();

        //"Opis œwiata" - przyci¹ganie itp.
        NxOgre::SceneDescription sceneDesc;
        sceneDesc.mGravity = NxOgre::Vec3(0, -9.8f, 0);
        sceneDesc.mName = "The World";
        
        //Przypisanie "Opisu" do samego œwiata.
        mScene = mWorld->createScene(sceneDesc);

        //Domyœlny matera³ fizyki (0).
        mScene->getMaterial(0)->setStaticFriction(0.5);
        mScene->getMaterial(0)->setDynamicFriction(0.5);
        mScene->getMaterial(0)->setRestitution(0.1);

        //Tworzy system renderowania fizyki. To nie jest konieczne. Fizyka mo¿e dzia³aæ i siê nie renderowaæ.
        mRenderSystem = new OGRE3DRenderSystem(mScene);
        mTime = NxOgre::TimeController::getSingleton();
    }