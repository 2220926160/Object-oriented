#include"head.h"

int main()
{
    Point obj1(10, 20), obj2;
    obj2.copy(obj1);
    obj1.display();
    obj2.display();

    return 0;
}