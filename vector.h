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

        void print();
        int getX();
        int getY();
};

#endif