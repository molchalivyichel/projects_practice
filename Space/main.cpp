
#include "vector.h"
#include "space.h"
#include "screen.h"

int main()
{
    Screen screen{ {10,10} };
    Space space{ {10,10}, 5 };
    char symboles[3] {'*', '@'};

    screen.setColor(10, 0);
    space.initializeHurdles();
    screen.setColor(3, 0);
    screen.printSpace(space, symboles);

    return 0;
}
