// - 编写一个小型公司的工资管理程序。
// - 该公司主要有4类人员：经理、兼职技术人员、销售员、销售经理。
// - 要求存储并显示每类人员的编号（从10000起编号）、姓名和月薪。
// - 其中月薪的计算方法为：经理固定月薪8000元，兼职技术人员100元/小时，销售员为当月销售额的4%，销售经理保底工资5000元另加其所管部门销售额的5%。

#include<iostream>
#include<string>

using namespace std;

class Employee                        // 基类 保护
{
protected:
    int no;                           // 编号
    string name;                      // 姓名
    float salary;                     // 月薪总额
    static int totalno;               // 公司目前编号最大值
public:
    Employee()
    {
        no = totalno++;               // 新员工编号为最大员工编号+1
        cout << "请输入职工姓名：" ;
        cin >> name;
        salary = 0.0;                 // 新员工月薪总额为0
    }

    virtual void pay() = 0;               // 计算月薪函数
    virtual void display() = 0;           // 输出员工信息函数

    ~Employee(){}
};

class Technician:public Employee      // 派生类，兼职技术人员类 私有
{
private:
    float hourlyrate;                 // 时薪
    int workhours;                    // 当月工作时数
public:
    Technician()
    {
        hourlyrate = 100;             // 时薪 100
        cout << name <<"本月工作时间：" ;
        cin >> workhours;
    }

    void pay()                        // 计算兼职技术员月薪函数
    {                                 // 计算月薪，按小时算
        salary = hourlyrate * (float)workhours;      
    }

    void display()                    // 显示兼职技术员信息函数
    {
        cout << "兼职技术人员：" << name <<endl;
        cout << "编号：" << no << endl;
        cout << "本月工资：" << salary <<endl;
    }

    ~Technician(){}
};

/*************** 注意：Salesman 和 Manager 必须是虚继承，不然销售经理类继承时会产生二义性，导致基类不明确。 ***************/
class Salesman:virtual public Employee        // 派生类，销售员类 保护
{
protected:
    float sales;                      // 当月销售额
    float commrate;                   // 按销售额提取酬金的百分比
public:
    Salesman()
    {
        commrate = 0.04f;             // 销售提成百分比为 4%
        cout << name <<"本月销售额：" ;
        cin >> sales;
    }

    void pay()                         // 计算销售员月薪函数
    {   
        salary = sales * commrate;     // 月薪 = 当月销售额 * 销售提成百分比
    }

    void display()                     // 显示兼职技术员信息函数
    {
        cout << "销售员：" << name <<endl;
        cout << "编号：" << no << endl;
        cout << "本月工资：" << salary <<endl;
    }

    ~Salesman(){}
};


class Manager:virtual public Employee          // 派生类，经理类 保护
{
protected:
    float mouthlypay;                  //  固定月薪数
public:
    Manager()
    {
        mouthlypay = 8000;             // 固定月薪 8000
    }

    void pay()                         // 计算经理月薪函数
    {
        salary = mouthlypay;           // 月薪总额为固定月薪数
    }

    void display()                     // 显示经理信息函数
    {
        cout << "经理：" << name <<endl;
        cout << "编号：" << no << endl;
        cout << "本月工资：" << salary <<endl;
    }

    ~Manager(){}
};


class Salesmanager: public Salesman, public Manager // 派生类，销售经理类
{
public:
    Salesmanager()
    {
        mouthlypay = 5000;             // 保底薪资 5000
        commrate = 0.05f;              // 销售提成百分比 5%
        cout << name << "所管部门本月销售额：" ;
        cin >> sales;
    }

    void pay()                         // 计算销售经理月薪函数
    {                                  // 月薪 = 固定月薪 + 销售提成
        salary = mouthlypay + commrate * sales;          
    }

    void display()                     // 显示销售经理信息函数
    {
        cout << "销售经理：" << name <<endl;
        cout << "编号：" << no << endl;
        cout << "本月工资：" << salary <<endl;
    }

    ~Salesmanager(){}
};


int Employee::totalno = 10000;         // 员工编号基数为 10000

/************  主函数  *************/
int main()
{ 
    Manager m1;
    Technician t1;
    Salesman s1;
    Salesmanager sm1;

    Employee *em[4] = {&m1, &t1, &s1, &sm1};

    cout << "上述人员的基本信息为：" << endl;
    for (int i = 0; i < 4; i++)
    {
        em[i]->pay();
        em[i]->display();
    }

    return 0;
}