#include<iostream>

using namespace std;

class Point
{
    public:
        void setxy(int, int);
        void display()
        {cout<<"("<<X<<","<<Y<<")";}
    private:
        int X, Y;
};