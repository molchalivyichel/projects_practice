#include <iostream>
#include "vector.h"

Vector::Vector(int _x, int _y) : x(_x), y(_y) { }
Vector::Vector(int _x) : x(_x), y(0) {}
Vector::Vector() : x(0), y(0) {}

void Vector::print()
{
    std::cout << "(X: " << this->x << ", Y: " << this->y << ")" << std::endl;
}

int Vector::getX()
{
    return this->x;
}

int Vector::getY()
{
    return this->y;
}