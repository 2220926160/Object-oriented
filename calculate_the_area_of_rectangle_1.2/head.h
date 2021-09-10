#include<iostream>

using namespace std;

class Rectangle_area
{
    public:
        void Set_data(float x, float y);
        void Calculate_area();
        void Output();
    private:
        float length, width, area;
};