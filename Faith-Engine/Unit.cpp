#include <precompiled.h>
#include <Unit.h>

Unit::Unit() : WorldObject()
{
    m_maxHealth = 0;
    m_health = 0;
}

Unit::~Unit()
{
}