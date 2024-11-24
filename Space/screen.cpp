#include "screen.h"
#include <iostream>
#include <windows.h>
#include "function_test.h"

Screen::Screen(const Vector _resolution) : resolution(_resolution) {};

Screen::~Screen()
{
    printMessage("Screen was delete");
}

void Screen::setColor(int textColor, int backgroundColor) const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = backgroundColor * 16 + textColor;
    SetConsoleTextAttribute(hConsole, color);
}

void Screen::printMassive(int* massive, int count) const
{
    for (int i = 0; i < count; ++i)
    {
        printMessage(massive[i]);
    }
}
