#include"head.h"

Point::Point(const Point &p)
{
    X = p.X;    Y = p.Y;
    cout<<"Copy function is called!";
    display();
}

Point func(Point p)
{
    int x = 20;
    int y = 20;
    Point pp(x, y);
    return pp;
}