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

        int* colorVoid;
        int* colorHurdle;
        const int countLimitColor = 2;

        friend class Screen;
    public:
        Space(const Vector _coords, const int _count_hurdle, char _symboleVoid,
            char _symboleHurdle, int* _colorVoid = nullptr, int* _colorHurdle = nullptr);
        Space(const Vector _coords, const int _count_hurdle, Vector* _massive_hurdle, char _symboleVoid,
            char _symboleHurdle, int* _colorVoid = nullptr, int* _colorHurdle = nullptr);
        ~Space();

        Vector* getMassiveHurdle() const;
        int* getColorVoid() const;
        int* getColorHurdle() const;
        char getSymboleVoid() const;
        char getSymboleHurdle() const;

        void sortMassiveHurdle();
        bool checkBorder(Vector value);
        void deletionMassiveHurdle();

        void editColor(int* color, int textColor, int backgroundColor);
        void editSymbole(char old_symbole, char new_symbole);
};

#endif