#include "head.h"

void input(Student * &head)
{
    int i = 0;

    Student *newnode, *p;
    long num;

    while (1)
    {
        cout << "请输入第" << i + 1 << "个学生的学号，输入0结束：";
        cin >> num;
        if(!num)
            break;

        newnode = new Student;
        newnode->num = num;

        cout << "请输入该学生的姓名：";
        cin >> newnode->name;
        cout << "请输入该学生的成绩：";
        cin >> newnode->score;
        i++;

        newnode->next = NULL;
        if (!head)
            head = newnode;
        else
            p->next = newnode;
        p = newnode;
    }

    cout << "共输入" << i << "个学生记录" << endl;
    return;
}

float average(Student *head)
{
    Student *p;
    p = head;
    int i = 0;
    float sum = 0.0;

    if (!p)
        return 0.0;

    while (p)
    {
        sum += p->score;
        i++;
        p = p->next;
    }

    return (sum / float(i));
}

void print(Student *head)
{
    Student *p;
    p = head;

    if (!p)
        return;

    cout << "姓名   学号   成绩" << endl;
    while (p)
    {
        cout << p->name << "    " << p->num << "    " << p->score << endl;
        p = p->next;
    }
}