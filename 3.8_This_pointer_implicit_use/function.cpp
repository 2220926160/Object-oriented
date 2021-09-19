#include"head.h"

Point::Point(int x, int y)
{
    X = x;
    Y = y;
}

void Point::display()
{
    cout<<this->X<<endl;
    cout<<this->Y<<endl;
}

Point::~Point()
{} 