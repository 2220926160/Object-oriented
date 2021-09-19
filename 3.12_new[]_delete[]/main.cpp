#include"head.h"

int main()
{
    Heapclass *ptr;
    ptr = new Heapclass[2];
    if (!ptr)
    {
        cout<<"Out of Memory！"<<endl;
        return 0;
    }
    cout<<"Exit main"<<endl;
    delete[]ptr;

    return 0;
}