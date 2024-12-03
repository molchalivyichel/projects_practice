#include <iostream>
#include <windows.h>
#include <string>
#include "screen.h"
#include "space.h"

Screen::Screen(const Vector _resolution) : resolution(_resolution) {};

Screen::Screen() {};

Screen::~Screen() {};

void Screen::setColor(int textColor, int backgroundColor) const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = backgroundColor * 16 + textColor;
    SetConsoleTextAttribute(hConsole, color);
}

void Screen::printMassive(int* massive, int count, bool endl) const
{
    for (int i = 0; i < count; ++i)
    {
        printMessage(massive[i], endl);
    }
}

void Screen::printMessage(int message, bool endl) const
{
    if (endl == true) {
        std::cout << message << std::endl;
    }
    else {
        std::cout << message;
    }
}

void Screen::printMessage(bool message, bool endl) const
{
    if (endl == true) {
        std::cout << message << std::endl;
    }
    else {
        std::cout << message;
    }
}

void Screen::printMessage(std::string message, bool endl) const
{
    if (endl == true){
        std::cout << message << std::endl;
    }
    else {
        std::cout << message;
    }
}

void Screen::printMessage(char message, bool endl) const
{
    if (endl == true) {
        std::cout << message << std::endl;
    }
    else {
        std::cout << message;
    }
}

void Screen::printMassiveVector(Vector* massiveVector, int count) const
{
    for (int i = 0; i < count; ++i)
    {
        (massiveVector[i]).print();
    }
}

unsigned int Screen::getTrueCountCoord(Space& space) const
{
    unsigned int count = 0;
    Vector vectorTime{ -1, -1 };

    for (int i = 0; i < space.count_hurdle; i++)
    {
        if (space.massive_hurdle[i].getX() == vectorTime.getX() && space.massive_hurdle[i].getY() == vectorTime.getY()) {
            count += 1;
        }
    }
    return count;
}

void Screen::printSpace(Space& space) const
{
    Vector vectorTime{ -1, -1 };
    unsigned int count = getTrueCountCoord(space);

    for (int i = 0; i < space.coords.getY(); i++)
    {
        for (int j = 0; j < space.coords.getX(); j++)
        {
            vectorTime = {j, i};
            
            if (space.massive_hurdle[count].getX() == vectorTime.getX() && space.massive_hurdle[count].getY() == vectorTime.getY()) {
                setColor(space.colorHurdle[0], space.colorHurdle[1]);
                printMessage(space.symboleHurdle, false);
                count += 1;
            }
            else {
                setColor(space.colorVoid[0], space.colorVoid[1]);
                printMessage(space.symboleVoid, false);
            }

        }
        printMessage("");
    }
}

void Screen::limitDisplay(Space& space, int radius, int voidTextColor, int voidBackgroundColor, int hurdleTextColor, int hurdleBackgroundColor) const
{
    
}

int Screen::cin_variable(std::string message)
{
    int variable = 0;
    std::cout << message;
    std::cin >> variable;
    return variable;
}