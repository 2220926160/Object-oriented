#include<iostream>

using namespace std;

class Point
{
    public:
        Point(int x, int y)
        {X = x; Y = y; cout<<"Comstructor is called!"; display();}
        Point(const Point &p);
        void display()
        {cout<<"("<<X<<","<<Y<<")"<<endl;}
        ~Point()
        {cout<<"Destructor is called!"; display();}
    private:
        int X, Y;
};

Point func(Point p);