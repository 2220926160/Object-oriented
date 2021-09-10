#include"head.h"

void Rectangle_area::Set_data(float x, float y)
{
    length = x;
    width = y;
}

void Rectangle_area::Calculate_area()
{
    area = length * width;
}

void Rectangle_area::Output()
{
    cout<<"矩形面积为"<<area;
}

