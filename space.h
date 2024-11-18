#ifndef SPACE_H  
#define SPACE_H

#include "vector.h"

class Space
{
    private:
        const Vector coords;
        const int count_hurdle;
        const int coord;
        Vector* massive_hurdle;
    public:
        Space(Vector _coords, const int _count_hurdle);
        ~Space();

        void initializeHurdles();
        void printHurdles() const; 

};

#endif