
#ifndef _Creature_H__
#define _Creature_H__

#include "Unit.h"

class Creature : public Unit
{
public:
    // Constructor
    explicit Creature();
    // Destructor
    virtual ~Creature();
};

#endif
