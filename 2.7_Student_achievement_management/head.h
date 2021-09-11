#include<iostream>

using namespace std;

/*
    学生成绩管理系统
    要求：1 创建一个单链表
          2 能输入和打印学生成绩
          3 能求出所有学生的成绩
*/

// 学生结构体
struct Student
{
    long num;   // 学号
    string name; // 姓名
    float score; // 成绩

    struct Student *next;
};

void input(Student * &head);
float average(Student *head);
void print(Student *head);