// 【例5.3】
// 动态联编

#include<iostream>

const double PI = 3.14;

using namespace std;

class Figure  // 定义基类
{
private:
    /* data */
public:
    Figure(/* args */){};
    ~Figure(){};
    virtual double area() const{return 0.0;} // 定义为虚函数 
};

class Circle:public Figure      // 定义派生类，公有继承方式
{
private:
    double R;
public:
    Circle(double MyR) {R = MyR;};
    virtual double area() const {return R * PI * R;} // 定义为虚函数
    ~Circle() {};
};

class Rectangle:public Figure   // 定义派生类，公有继承方式
{
private:
    double L, W;
public:
    Rectangle(double MyL, double MyW) {L = MyL; W = MyW;};
    virtual double area() const {return L * W;} // 定义为虚函数
    ~Rectangle() {};
};

void function(Figure &p)  // 形参为基类的引用
{
    cout << p.area() << endl;
}

int main()
{
    Figure fig;                     // 基类Figure对象
    cout << "Area of figure is ";
    function(fig);

    Circle cir(3.0);                // Circle 派生类对象
    cout << "Area of circle is ";
    function(cir);

    Rectangle rec(4.0, 5.0);        // Rectangle 派生类对象
    cout << "Area of rectangle is ";
    function(rec);

    return 0;
}