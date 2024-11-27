
#include "vector.h"
#include "space.h"
#include "screen.h"

int main()
{
    Screen screen{ {10,10} };
    
    Vector* massive_hurdle = new Vector[8]{ {2,1},{1,0},{3,0},{0,1},{4,1}, {1,2}, {3,2}, {2,3} };
    char symboles[2]{(char)11,'#'};
    Space space{ {5,5}, 5, symboles[0], symboles[1],massive_hurdle};
    space.deletionMassiveHurdle();
    space.sortMassiveHurdle();

    screen.printSpace(space, 15, 0, 5, 0);

    return 0;
}
