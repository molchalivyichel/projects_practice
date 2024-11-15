#include <iostream>
#include "vector.h"
#include "space.h"

Space::Space(Vector _coords, const int _count_hurdle, const int _coord = 2)
 : coords(_coords), count_hurdle(_count_hurdle), coord(_coord) {}

Space::Space(Vector _coords, const int _count_hurdle)
 : coords(_coords), count_hurdle(_count_hurdle), coord(2) {}

Space::~Space()
{
    for (int i = 0; i < count_hurdle; ++i)
    {
        delete[] massive_hurdle[i];
    }
    delete[] massive_hurdle;
    massive_hurdle = nullptr;
}

void Space::initializeHurdles()
{
    
}