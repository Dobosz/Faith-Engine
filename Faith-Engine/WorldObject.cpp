
#include <WorldObject.h>

WorldObject::WorldObject() : m_positionX(0.0f), m_positionY(0.0f), m_positionZ(0.0f)
{
    // Constructor, Initialize empty variables.
}

void WorldObject::Relocate(float x, float y, float z)
{
    m_positionX = x;
    m_positionY = y;
    m_positionZ = z;
}