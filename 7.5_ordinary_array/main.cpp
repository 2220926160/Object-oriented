#include <iostream>
#include <string.h>

using namespace std;

template <typename T> // 函数模板
T Larger(T a, T b)
{
    return a > b ? a : b;
}
int Larger(int a, float b)   // 重载函数1
{
    return a > b ? a : b;
}
char *Larger(char *a, char *b)     // 重载函数2
{
    return strcmp(a, b) > 0 ? a : b;
}

int main()
{
    char a = '4', b = '5';
    int c = 5;

    cout << "max(" << a << "," << b << ") = " << Larger(a, b) << endl;
    cout << "ASC(a) = " <<(int)a << endl;
    cout << "max(" << a << "," << c << ") = " << Larger(a, c) << endl;
    char *p, *h;
    p = "qaz";
    h = "wsx";
    cout << "max(" << p << "," << h << ") = " << Larger(p, h) << endl;


    return 0;
}
