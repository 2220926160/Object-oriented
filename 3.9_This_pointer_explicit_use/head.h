#include<iostream>

using namespace std;

class Point
{
    public:
        Point();
        Point(int x, int y);
        void display();
        void copy(Point &obj);
        ~Point();
    private:
        int X, Y;
};
