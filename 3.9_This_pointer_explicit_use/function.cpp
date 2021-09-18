#include"head.h"

void Point::display()
{
    cout<<X<<" ";
    cout<<Y<<endl;
}

void Point::copy(Point &obj)
{
    if(this != &obj)         // this指针的显式使用，避免无意义的更新
        *this = obj;
}

Point::Point()
{
    X = 0;
    Y = 0;
}

Point::Point(int x, int y)
{
    X = x;
    Y = y;
}

Point::~Point()
{}