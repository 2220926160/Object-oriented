// 【例5.11】
// 使用虚构函数
// 结果：
// Subclass destructor is called.    
// Base destructor is called.  

#include<iostream>

using namespace std;

class Base
{
public:
    Base() {};
    virtual ~Base() {cout << "Base destructor is called.";}
};

class Subclass:public Base
{
public:
    Subclass() {};
    ~Subclass();
};

Subclass::~Subclass() {cout << "Subclass destructor is called." << endl;}


int main()
{ 
    Base *b = new Subclass;
    delete b;  

    return 0;
}

/*********  基类的析构函数由派生类的析构函数调用  *********/  