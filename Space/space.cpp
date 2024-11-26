#include "vector.h"
#include "space.h"
#include "screen.h"

Space::Space(const Vector _coords, const int _count_hurdle)
 : coords(_coords), count_hurdle(_count_hurdle)
{
    massive_hurdle = new Vector[count_hurdle];
}

Space::~Space()
{
    delete[] massive_hurdle;
    massive_hurdle = nullptr;
}

void Space::initializeHurdles()
{
    int _x, _y = 0;
    Screen timeScreen;

    for (int i = 0; i < count_hurdle; ++i)
    {
        _x = timeScreen.cin_variable("X: ");
        _y = timeScreen.cin_variable("Y: ");

        massive_hurdle[i] = Vector(_x, _y);
    }
}

