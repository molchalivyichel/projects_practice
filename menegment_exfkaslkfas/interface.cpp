#include <iostream>
#include <filesystem> 
#include "windowcmd.h"
#include "interface.h"

void fill(std::string symbole, int height, int widht)
{
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= widht; j++) {
            std::cout << symbole;
        }
    }
}

void printError(std::string error)
{
    setColor(4);
    std::cerr << "Error: " << error << "\n";
    setColor();
}