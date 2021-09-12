#include"head.h"

int main()
{
    Point p1, *p2;
    p1.setxy(3, 4);
    cout<<"第一个点的位置是：";
    p1.display();
    p2 = &p1;
    p2->setxy(5, 6);
    cout<<"第二个点的位置是：";
    p2->display();

    return 0;
}