#ifndef VECTOR_H  
#define VECTOR_H

class Vector 
{
    private:
        int x;
        int y;
    public:
        Vector(int _x, int _y);
        Vector(int _x);
        Vector();

        void print() const;
        int getX() const;
        int getY() const;

        void editX(int x);
        void editY(int y);
};

#endif