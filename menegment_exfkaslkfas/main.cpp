#include <iostream>
#include <fstream>
#include <string>
#include "windowcmd.h"
#include "interface.h"

int main() {
    int width = 750; 
    int height = 750; 


    //макс размер для вмещения всех символов - 750 на 750 - 4094символов
    //750 на 750 - 88*45
    setConsoleSize(width, height);
    lockConsoleResize();

    std::string line;
    std::ifstream in("filename.txt");
    if (in.is_open()) {
        while (std::getline(in, line)) {
            std::cout << line << std::endl;
        }
    }


    std::string i = "";
    std::cin >> i;
    std::cout <<"\n";

    std::cout << i.size();


    return 0;
}
