#include <iostream>
#include <fstream>
#include <string>
#include <filesystem> 
#include "windowcmd.h"
#include "interface.h"
#include "workFiles.h"

namespace fs = std::filesystem;


int main() {
    
    useRus();
    const int width = 750; 
    const int height = 750; 

    setConsoleSize(width, height);
    //lockConsoleResize();
    setColor(2);

    std::string filename = "filename.txt";


    Directory directory{ "E:\\" }; // либо \\ или / fs::current_path().string()
    std::cout << directory.getPathDirectory() << "\n";
    directory.prewiewFilesDirectory(true);
    std::cin.get();
    //ctrl+k+c, ctrl+k+u
    /*if (std::filesystem::exists(filename)) {
        std::cout << filename << "\n";

        char symbole;
        std::cout << "Let`s go to edit file(y/n): ";
        std::cin >> symbole;
        if (symbole == 'y' || symbole == 'Y') {
            std::ofstream out;
            out.open(filename);
            if (out.is_open()) {
                std::string message = "";
                std::cin >> message;
                out << message << '\n';
                out.close();
            }
        }
        else if (symbole == 'n' || symbole == 'N') {
            std::cout << "no problem\n";
        }

    } else {
        char symbole;
        std::cout << "none\n" << "Let`s go to create file(y/n): ";
        std::cin >> symbole;
        if (symbole == 'y' || symbole == 'Y') {
            std::ofstream outfile(filename);
        } else if (symbole == 'n' || symbole == 'N') {
            std::cout << "no problem\n";
        }
    }*/

    //макс размер для вмещения всех символов - 750 на 750 - 4094символов
    //750 на 750 - 88*45


    return 0;
}
