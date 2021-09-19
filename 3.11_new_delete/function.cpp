#include"head.h"

Heapclass::Heapclass()
{
    i = 0;
    cout<<"Default constructor of Heapclass"<<endl;
}

Heapclass::Heapclass(int x)
{
    i = x;
    cout<<"Constructor of Heapclass"<<endl;
}

Heapclass::~Heapclass()
{
    cout<<"Destructor of Heapclass"<<endl;
}
