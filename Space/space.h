#ifndef SPACE_H  
#define SPACE_H

#include "vector.h"

class Screen;

class Space
{
    private:
        const Vector coords;
        const int count_hurdle;
        Vector* massive_hurdle;
        char symboleVoid;
        char symboleHurdle;

        friend class Screen;
    public:
        Space(const Vector _coords, const int _count_hurdle, char _symboleVoid, char _symboleHurdle);
        Space(const Vector _coords, const int _count_hurdle, char _symboleVoid, char _symboleHurdle, Vector* _massive_hurdle);
        ~Space();

        Vector* getMassiveHurdle() const;
        void initializeHurdles();
        void sortMassiveHurdle();
        bool checkBorder(Vector value);
        void deletionMassiveHurdle();

};

#endif