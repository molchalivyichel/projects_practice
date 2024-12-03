
#include "vector.h"
#include "space.h"
#include "screen.h"

int main()
{
    Screen screen{ {10,10} };
    
    Vector* massive_hurdle = new Vector[8]{ {2,1},{1,0},{3,0},{0,1},{4,1}, {1,2}, {3,2}, {2,3} };
    char symboles[2]{(char)11,'#'};
    int* colorVoid = new int[2] {15,2};
    int* colorHurdle = new int[2] {5, 5};

    Space space{ {5,5},8,massive_hurdle,symboles[0],symboles[1],colorVoid, colorHurdle };
    space.deletionMassiveHurdle();
    space.sortMassiveHurdle();

    screen.printSpace(space);
    screen.setColor(7, 0);
    return 0;
}
