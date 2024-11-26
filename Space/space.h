#ifndef SPACE_H  
#define SPACE_H

#include "vector.h"

class Screen;

class Space
{
    private:
        const Vector coords;
        const int count_hurdle;
        Vector* massive_hurdle;
        friend class Screen;
    public:
        Space(Vector _coords, const int _count_hurdle);
        ~Space();

        void initializeHurdles();

};

#endif