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

void printPath(wchar_t const* path)
{
    if (path == L"") {
        std::wcout << "incorrect path" << L"\n";
    }
    std::wcout << path << L"\n";
}

void printPath(char const* path)
{
    if (path == "") {
        std::cout << "incorrect path" << "\n";
    }
    std::cout << path << "\n";
}