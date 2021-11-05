#include <iostream>
#include <list>   // 包含双向链表容器头文件
#include <iterator> // 迭代器头文件 

using namespace std;

int main()
{
    list<int> nums; // 整型双向链表，长度为0
    nums.insert(nums.begin(), -99); // 在链表第1个位置插入-99
    nums.insert(nums.begin(), 4); // 在链表第1个位置插入4
    nums.insert(nums.end(), 50); // 在链表末尾插入5

    list<int>::const_iterator p1; // p1是整型双向链表的迭代子
    cout << "正向输出双向链表中所有元素" << endl;
    for(p1 = nums.begin(); p1 != nums.end(); p1++)
        cout << *p1 << " "; // 依次输出双向链表中所有元素：4 -99 50
    cout << endl;

    list<int>::const_reverse_iterator p2; // p2是整型双向量表的迭代子
    p2 = nums.rbegin(); // 反向迭代指向最后1个元素
    cout << "逆向输出双向链表中所有元素" << endl;
    while(p2 != nums.rend()) // 当反向迭代不指向第1个元素
    {
        cout << *p2 << " "; // 逆向输出双向链表中所有元素：50 -99 4
        p2++;
    }
    cout << endl;

    return 0;
}
/***********************
运行结果：
正向输出双向链表中所有元素
4 -99 50 
逆向输出双向链表中所有元素
50 -99 4 
***********************/