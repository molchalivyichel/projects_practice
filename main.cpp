#include "vector.h"

int main()
{
    Vector vector = (2,3);
    vector.print();
    vector.editX(10);
    vector.editY(20);
    vector.print();

    return 0;
}
