#include <iostream>

void fill(std::string symbole, int height, int widht)
{
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= widht; j++) {
            std::cout << symbole;
        }
    }
}