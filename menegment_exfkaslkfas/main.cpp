#include <iostream>
#include "windowcmd.h"

int main() {
    int width = 1000; //120 символов в 1000пк 8.3333333
    int height = 1000; //57 символов в 1000пк 17,5438596491
    setConsoleSize(width, height);
    //lockConsoleResize();
    setColor(2, 7);

    for (int j = 0; j < height; j += 17.54) {
        for (int i = 0, h = 0; i < width; i += 8.33, h++) {
            if (h == 10) {
                h = 0;
            }
            std::cout << h;
        }
    }
    setColor(2, 1);

    std::cin.get();

    return 0;
}
