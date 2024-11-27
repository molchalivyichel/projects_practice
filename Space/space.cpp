#include "vector.h"
#include "space.h"

Space::Space(const Vector _coords, const int _count_hurdle, char _symboleVoid, char _symboleHurdle)
 : coords(_coords), count_hurdle(_count_hurdle), symboleVoid(_symboleVoid), symboleHurdle(_symboleHurdle)
{
    massive_hurdle = new Vector[count_hurdle];
}

Space::Space(const Vector _coords, const int _count_hurdle, char _symboleVoid, char _symboleHurdle, Vector* _massive_hurdle)
 : coords(_coords), count_hurdle(_count_hurdle), symboleVoid(_symboleVoid), symboleHurdle(_symboleHurdle), massive_hurdle(_massive_hurdle) { }

Space::~Space()
{
    delete[] massive_hurdle;
    massive_hurdle = nullptr;
}

Vector* Space::getMassiveHurdle() const
{
    return this->massive_hurdle;
}

bool Space::checkBorder(Vector value)
{
    
    if (value.getY() >= coords.getY() || value.getY() < 0)
    {
        return false;
    }
    else if (value.getX() >= coords.getX() || value.getX() < 0) {
        return false;
    }
    return true;
}

void Space::deletionMassiveHurdle()
{
    for (int i = 0; i < count_hurdle; i++)
    {
        if (checkBorder(massive_hurdle[i]) == 0)
        {
            massive_hurdle[i] = { -1,-1 };
        }
    }
}

void Space::sortMassiveHurdle()
{
    for (bool check = false, timeCheck = true; check == false ;)
    {
        Vector timeElement;
        timeCheck = true;
        for (int i = 0; i < count_hurdle - 1; i++)
        {
            if (massive_hurdle[i].getY() > massive_hurdle[i + 1].getY()) {
                timeElement = massive_hurdle[i];
                massive_hurdle[i] = massive_hurdle[i + 1];
                massive_hurdle[i + 1] = timeElement;
                timeCheck = false;
            }
        }
        check = timeCheck;
    }

    for (bool check = false, timeCheck = true; check == false;)
    {
        Vector timeElement;
        timeCheck = true;
        for (int i = 0; i < count_hurdle - 1; i++)
        {
            if (massive_hurdle[i].getX() > massive_hurdle[i + 1].getX() &&
                massive_hurdle[i].getY() == massive_hurdle[i + 1].getY()) {

                timeElement = massive_hurdle[i];
                massive_hurdle[i] = massive_hurdle[i + 1];
                massive_hurdle[i + 1] = timeElement;
                timeCheck = false;
            }
        }
        check = timeCheck;
    }
}