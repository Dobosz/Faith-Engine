#include <precompiled.h>
#include <Unit.h>

Unit::Unit(Ogre::String n)
{
    Unit::setName(n);
}
Unit::Unit(Ogre::String n, unsigned int x, unsigned int y, unsigned int z)
{
    Unit::setName(n);
    Unit::setGridPosision(x,y,z);
}
Unit::~Unit()
{
}
grid Unit::getGridPosision(){ return Unit::grid_pos; }
global Unit::getGlobalPosision() { return Unit::global_pos; }
Ogre::String Unit::getName() { return Unit::name; }
bool Unit::isVisible() { return Unit::visible; }
void Unit::setGridPosision(unsigned int x, unsigned int y, unsigned int z)
{
    Unit::grid_pos.x = x;
    Unit::grid_pos.y = y;
    Unit::grid_pos.z = z;
}
void Unit::setGlobalPosision(double x, double y, double z)
{
    Unit::global_pos.x = x;
    Unit::global_pos.y = y;
    Unit::global_pos.z = z;
}
void Unit::setName(Ogre::String n)
{
    Unit::name = n;
}
void Unit::setVisible(bool v)
{
    Unit::visible = v;
}
void Unit::Move(int x, int y, int z)
{
    Unit::grid_pos.x += x;
    Unit::grid_pos.y += y;
    Unit::grid_pos.z += z;
}