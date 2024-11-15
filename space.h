#include "vector.h"

#ifndef SPACE_H  
#define SPACE_H

class Space
{
    private:
        Vector coords;
        const int count_hurdle;
        const int coord;
        int** massive_hurdle;
    public:
        Space(Vector _coords, const int _count_hurdle, const int coord = 2);
        Space(Vector _coords, const int _count_hurdle);
        ~Space();

        void initializeHurdles();

};

#endif