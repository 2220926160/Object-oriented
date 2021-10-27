// 【例5.8】
// 输出结果：This is Subclass func1

#include<iostream>

using namespace std;

class Base
{
public:
    virtual void func1()
    {
        cout<<"This is Base func1"<<endl;
    }
    void func2(){func1();}
};
class Subclass:public Base
{
    virtual void func1()
    {
        cout<<"This is Subclass func1"<<endl;
    }
};
int main()
{
    Subclass sc;
    sc.func2();
    return 0;
}