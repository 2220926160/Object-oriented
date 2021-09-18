#include"head.h"

int main()
{
    Point obj1(10, 20), obj2(8, 9), *p;
    p = &obj1;
    p->display();
    p = &obj2;
    p->display();

    return 0;
}