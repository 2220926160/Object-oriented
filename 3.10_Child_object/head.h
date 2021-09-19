#include<iostream>

using namespace std;

class Part
{
    public:
        Part();
        Part(int x);
        ~Part();
    private:
        int val;
};

class Whole
{
    public:
        Whole();
        Whole(int i);
        ~Whole();
    private:
        Part p1;
        Part p2;
};