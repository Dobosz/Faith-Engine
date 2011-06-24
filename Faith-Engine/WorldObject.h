#include <Unit.h>
#include <NxOgre.h>

#ifndef _WorldObject_H__
#define _WorldObject_H__

struct size_struct
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

class WorldObject : public Unit
{
    private:
        Ogre::SceneNode * ObjectNode;
        AnimationBlender * Animation;
        bool CastShadow;
        size_struct ObjectSize;
        Ogre::Entity * Entity;
    public:
        // Constructor
        explicit WorldObject(char *, unsigned int, unsigned int, unsigned int, char * mesh, bool);
        explicit WorldObject(char *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, char * mesh, bool);
        // Destructor
        virtual ~WorldObject ();
        //Functions
        void setObjectSize(unsigned int, unsigned int, unsigned int);
        void setShadow(bool);
        void setAnimation(AnimationBlender *);
        bool itCastShadow();
        AnimationBlender * getAnimation();
        size_struct getObjectSize();
        void BlendAnimation(char* animation, double, AnimationBlender::BlendingTransition, bool);
};

#endif
