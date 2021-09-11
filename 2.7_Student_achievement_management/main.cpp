#include"head.h"

int main()
{
    Student *stu = NULL;

    input(stu);
    float ave = average(stu);
    print(stu);

    cout<<"全班平均成绩为："<<ave<<endl;

    return 0;
}