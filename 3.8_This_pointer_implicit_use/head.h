#include<iostream>

using namespace std;

class Point
{
    public:
        Point(int x, int y);
        void display();
        ~Point();
    private:
        int X, Y;
};