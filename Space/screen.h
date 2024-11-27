#ifndef SCREEN_H
#define SCREEN_H

#include "vector.h"
#include "space.h"

#include <string>

class Screen
{
private:
    const Vector resolution;
    const int massive_color[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
public:
    Screen(const Vector _resolution);
    Screen();
    ~Screen();
    void setColor(int textColor, int backgroundColor) const;
    void printMassive(int* massive, int count, bool endl = true) const;

    void printMessage(int message, bool endl = true) const;
    void printMessage(bool message, bool endl) const;
    void printMessage(std::string message, bool endl = true) const;
    void printMessage(char message, bool endl = true) const;

    void printMassiveVector(Vector* massiveVector, int count) const;
    void printSpace(Space& space, int voidTextColor = 0, int voidBackgroundColor = 0, int hurdleTextColor = 0, int hurdleBackgroundColor = 0) const;
    int cin_variable(std::string message = "");
};


#endif