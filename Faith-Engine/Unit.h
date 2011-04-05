
#ifndef _Unit_H__
#define _Unit_H__

#include "WorldObject.h"

//using namespace Ogre;

class Unit : public WorldObject
{
    protected:
        unsigned int m_health;
        unsigned int m_maxHealth;

        explicit Unit ();

    public:
    
        // Destructor
        virtual ~Unit ( );

        unsigned int GetHealth() { return m_health; }
        unsigned int GetMaxHealth() { return m_maxHealth; }
        void SetHealth(unsigned int val) { m_health = val; }
};

#endif
