
#include "vector.h"
#include "space.h"
#include "screen.h"

int main()
{
    Screen screen{ {10,10} };
    screen.setColor(10, 0);

    Space space{{10,10}, 5};
    space.initializeHurdles();
    screen.setColor(3, 0);

    screen.printMassive()


    return 0;
}
