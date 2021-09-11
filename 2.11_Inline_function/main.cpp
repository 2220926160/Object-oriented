#include"head.h"

int main()
{
    int x1, x2;
    double y = 8.6;
    x1 = sum(3, 4);
    cout<<"3+4=";
    print(x1);
    x2 = sum(3, 4, 5);
    cout<<"3+4+5=";
    print(x2);
    cout<<"1 double is ";
    print(y);

    return 0;
}