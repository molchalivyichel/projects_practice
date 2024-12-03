#include "vector.h"
#include "space.h"

Space::Space(const Vector _coords, const int _count_hurdle, char _symboleVoid,
    char _symboleHurdle, int* _colorVoid, int* _colorHurdle)

 : coords(_coords), count_hurdle(_count_hurdle), symboleVoid(_symboleVoid),
    symboleHurdle(_symboleHurdle), colorVoid(_colorVoid), colorHurdle(_colorHurdle)
{
    massive_hurdle = new Vector[count_hurdle];

    if (colorVoid == nullptr || sizeof(colorVoid)/sizeof(colorVoid[0]) > countLimitColor || sizeof(colorVoid) / sizeof(colorVoid[0]) < countLimitColor) {
        colorVoid = nullptr;
        colorVoid = new int[countLimitColor];
        for (int i = 0; i < countLimitColor; i++)
        {
            if (i % 2 == 0) {
                colorVoid[i] = 7;
            }
            else {
                colorVoid[i] = 0;
            }
        }
    }
    if (colorHurdle == nullptr || sizeof(colorHurdle) / sizeof(colorHurdle[0]) > countLimitColor || sizeof(colorHurdle) / sizeof(colorHurdle[0]) < countLimitColor) {
        colorHurdle = nullptr;
        colorHurdle = new int[countLimitColor];

        for (int i = 0; i < countLimitColor; i++)
        {
            if (i % 2 == 0) {
                colorHurdle[i] = 7;
            }
            else {
                colorHurdle[i] = 0;
            }
        }
    }
}

Space::Space(const Vector _coords, const int _count_hurdle, Vector* _massive_hurdle, char _symboleVoid,
    char _symboleHurdle, int* _colorVoid, int* _colorHurdle)

 : coords(_coords), count_hurdle(_count_hurdle), massive_hurdle(_massive_hurdle),symboleVoid(_symboleVoid),
    symboleHurdle(_symboleHurdle), colorVoid(_colorVoid), colorHurdle(_colorHurdle) { }

Space::~Space()
{
    delete[] massive_hurdle;
    massive_hurdle = nullptr;
    
    delete[] colorVoid;
    colorVoid = nullptr;

    delete[] colorHurdle;
    colorHurdle = nullptr;
}

Vector* Space::getMassiveHurdle() const
{
    return this->massive_hurdle;
}

int* Space::getColorVoid() const
{
    return this->colorVoid;
}

int* Space::getColorHurdle() const
{
    return this->colorHurdle;
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

void Space::editColor(int* color,int textColor, int backgroundColor) 
{
    if (color == colorVoid || color == colorHurdle)
    {
        for (int i = 0; i < countLimitColor; i++)
        {
            if (i % 2 == 0) {
                colorVoid[i] = textColor;
            }
            else {
                colorVoid[i] = backgroundColor;
            }
        }
    }
}