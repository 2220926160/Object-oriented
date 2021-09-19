#include"head.h"

int main()
{
    Heapclass *pa1, *pa2;
    pa1 = new Heapclass(4);
    pa2 = new Heapclass();
    if(!pa1 || !pa2)
    {
        cout<<"Out of Memory!"<<endl;
        return 0;
    }
    cout<<"Exit main"<<endl;
    delete pa1;
    delete pa2;

    return 0;
}