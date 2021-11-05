#include<iostream>
#include<string>

using namespace std;

template <typename T>   // 函数模板
T Larger(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    int a, b;
    cout << "Input two integers to a&b:";
    cin >> a >> b;
    cout << "max(" << a << "," << b << ")=" << Larger(a, b) << endl;

    char c, d;
    cout << "Input two chars to c&f:";
    cin >> c >> d;
    cout << "max(" << c << "," << d << ")=" << Larger(c, d) << endl;

    float x, y;
    cout << "Input two floats to x&y:";
    cin >> x >> y;
    cout << "max(" << x << "," << y << ")=" << Larger(x, y) << endl;
    
    string p, h; 
    cout << "Input two strings to p&h:";
    cin >> p >> h;
    cout << "max(" << p << "," << h << ")=" << Larger(p, h) << endl;

    return 0;
}



/******** 编译程序时，编译器根据调用语句中实际数据类型而产生相应的函数 ********/

