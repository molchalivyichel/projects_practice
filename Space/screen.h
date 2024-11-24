#ifndef SCREEN_H
#define SCREEN_H

#include "vector.h"

class Screen
{
private:
    const Vector resolution;
    const int massive_color[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
public:
    Screen(const Vector _resolution);
    ~Screen();
    void setColor(int textColor, int backgroundColor) const;
    void printMassive(int* massive, int count) const;
};


#endif