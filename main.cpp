
#include "vector.h"
#include "space.h"

using namespace tabulate;

int main()
{
    Vector space_coords{10,10};
    const int count_hurdle = 5;
    Space space{space_coords, count_hurdle};
    space.initializeHurdles();
    space.printHurdles();

    return 0;
}
