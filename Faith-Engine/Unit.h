
#ifndef _Unit_H__
#define _Unit_H__

        struct grid
        {
        unsigned int x;
        unsigned int y;
        unsigned int z;
        };

        struct global
        {
        double x;
        double y;
        double z;
        };

class Unit
{
    protected:
        global global_pos;
        grid grid_pos;
        char * name;
        bool visible;
    public:
        // Constructors
        explicit Unit (char *);
        explicit Unit (char *, unsigned int, unsigned int, unsigned int);
        // Destructor
        virtual ~Unit ();
        // Functions
        grid getGridPosision();
        global getGlobalPosision();
        char * getName();
        bool isVisible();
        void setGridPosision(unsigned int, unsigned int, unsigned int);
        void setGlobalPosision(double, double, double );
        void setName(char *);
        void setVisible(bool);
        void Move(int, int, int);
};

#endif
