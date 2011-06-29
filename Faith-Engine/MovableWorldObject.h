#include <WorldObject.h>
#include <NxOgre.h>
#ifndef _MovableWorldObject_H__
#define _MovableWorldObject_H__

class MovableWorldObject : public WorldObject
{
protected:
    OGRE3DBody * PhysicBody;
public:
    //Constructor
    explicit MovableWorldObject(Ogre::String, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Ogre::String, double, bool, int);
    //Destructor
    virtual ~MovableWorldObject();
    //Functions
};

#endif