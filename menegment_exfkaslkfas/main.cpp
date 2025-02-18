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
    int width = 750; 
    int height = 750; 

    setConsoleSize(width, height);
    lockConsoleResize();
    setColor(2);

    std::string filename = "filename.txt";


    Directory directory{ "E:\\projects_programming" }; // либо \\ или / fs::current_path().string()
    directory.prewiewFilesDirectory();
    
    

    /*if (std::filesystem::exists(filename)) {
        std::cout << filename << "\n";

        char symbole;
        std::cout << "let`s go to edit file(y/n): ";
        std::cin >> symbole;
        if (symbole == 'y') {
            std::ofstream out;
            out.open(filename);
            if (out.is_open()) {
                std::string message = "";
                std::cin >> message;
                out << message << '\n';
                out.close();
            }
        }
        else if (symbole == 'n') {
            std::cout << "no problem\n";
        }

    } else {
        char symbole;
        std::cout << "none file\n" << "let`s go to create file(y/n): ";
        std::cin >> symbole;
        if (symbole == 'y') {
            std::ofstream outfile(filename);
        } else if (symbole == 'n') {
            std::cout << "no problem\n";
        }
    }*/

    //макс размер для вмещения всех символов - 750 на 750 - 4094символов
    //750 на 750 - 88*45


    return 0;
}
