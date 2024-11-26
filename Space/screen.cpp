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

void Screen::printMassive(int* massive, int count, bool endl = true) const
{
    for (int i = 0; i < count; ++i)
    {
        printMessage(massive[i], endl);
    }
}

void Screen::printMessage(int message, bool endl = true) const
{
    if (endl == true) {
        std::cout << message << std::endl;
    }
    else {
        std::cout << message;
    }
}

void Screen::printMessage(std::string message, bool endl = true) const
{
    if (endl == true){
        std::cout << message << std::endl;
    }
    else {
        std::cout << message;
    }
}

void Screen::printSpace(Space& space, char* symboles) const
{
    for (int i = 0; i < space.coords.getY(); i++)
    {
        for (int j = 0; j < space.coords.getX(); j++)
        {
            printMessage(&symboles[0], false);
        }
    }
}

int Screen::cin_variable(std::string message)
{
    int variable = 0;
    std::cout << message;
    std::cin >> variable;
    return variable;
}