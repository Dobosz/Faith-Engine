#include <precompiled.h>
#include <MainListener.h>
#include <NxOgreMain.h>

NxOgreMain::NxOgreMain(void)
    {
        //Tworzy �wiat
        mWorld = NxOgre::World::createWorld();

        //"Opis �wiata" - przyci�ganie itp.
        NxOgre::SceneDescription sceneDesc;
        sceneDesc.mGravity = NxOgre::Vec3(0, -9.8f, 0);
        sceneDesc.mName = "The World";
        
        //Przypisanie "Opisu" do samego �wiata.
        mScene = mWorld->createScene(sceneDesc);

        //Domy�lny matera� fizyki (0).
        mScene->getMaterial(0)->setStaticFriction(0.5);
        mScene->getMaterial(0)->setDynamicFriction(0.5);
        mScene->getMaterial(0)->setRestitution(0.1);

        //Tworzy system renderowania fizyki. To nie jest konieczne. Fizyka mo�e dzia�a�Ei si�Enie renderowa�E
        mRenderSystem = new OGRE3DRenderSystem(mScene);
        mTime = NxOgre::TimeController::getSingleton();

        //Opening folder.
        NxOgre::ResourceSystem::getSingleton()->openArchive("media", "file:media/models");
    }
void NxOgreMain::CreateMaterial(int id, double StaticFriction, double DynamicFriction, double Restitution)
{
        mScene->getMaterial(id)->setStaticFriction(StaticFriction);
        mScene->getMaterial(id)->setDynamicFriction(DynamicFriction);
        mScene->getMaterial(id)->setRestitution(Restitution);
}