#include<iostream>
#include<string>

using namespace std;

template <typename T>   // 函数模板 1
T Larger(T a, T b)
{
    return a > b ? a : b;
}
template <typename T>   // 函数模板 2
T Larger(T a[], int n)
{
    T temp;
    int i = 0;
    temp = a[0];

    for(; i < n; i++)
    {
        temp = a[i] > temp? a[i] : temp; 
    }

    return temp;
}


int main()
{
    int a, b;
    cout << "Input two integers to a&b:";
    cin >> a >> b;
    cout << "max(" << a << "," << b << ")=" << Larger(a, b) << endl;

    int i, aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "The original array:" << endl;
    for(i = 0; i < 10; i++) cout << aa[i] << " ";
    cout << endl;
    cout << "max of 10 integers is " << Larger(aa, 10) << endl;

    return 0;
}

/********* 程序中定义的是同名函数模板，是重载的函数模板。 ********/
/********* C++编译器将根据调用的参数类型和个数选择可用于实例化的函数模板。 ********/