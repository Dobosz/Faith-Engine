
#ifndef _WorldObject_H__
#define _WorldObject_H__

class WorldObject
{
    private:
        float m_positionX, m_positionY, m_positionZ;
    public:
        // Constructor
        explicit WorldObject();
        // Destructor
        virtual ~WorldObject ( ) {}

        void Relocate(float x, float y, float z);

        float GetPositionX( ) const { return m_positionX; }
        float GetPositionY( ) const { return m_positionY; }
        float GetPositionZ( ) const { return m_positionZ; }

};

#endif
