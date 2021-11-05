#include <iostream>
#include <string>

using namespace std;

template <typename T> // 函数模板
T Larger(T a, T b)
{
    return a > b ? a : b;
}
int Larger(int a, float b) // 用普通函数重载函数模板
{
    return a > b ? a : b;
}

int main()
{
    char a = '4', b = '5';
    int c = 5;

    cout << "max(" << a << "," << b << ") = " << Larger(a, b) << endl;
    cout << "ASC(a) = " <<(int)a << endl;
    cout << "max(" << a << "," << c << ") = " << Larger(a, c) << endl;

    return 0;
}

/********* Larger(a, b)调用函数模板，Larger(a, c)调用普通函数 ********/