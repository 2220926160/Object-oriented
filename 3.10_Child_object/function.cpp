#include"head.h"

Part::Part()
{
    val = 0;
    cout<<"Default constructor of Part"<<endl;
}

Part::Part(int x)
{
    val = x;
    cout<<"Constructor of Part"<<endl;
}

Part::~Part()
{
    cout<<"Destructor of Part"<<endl;
}

Whole::Whole()
{
}

Whole::Whole(int i):p1(), p2(i)
{
    cout<<"Constructor of Whole"<<endl;
}

Whole::~Whole()
{
    cout<<"Destructor of Whole"<<endl;
}