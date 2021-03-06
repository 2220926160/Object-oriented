## 面向对象程序设计教程（C++语言描述）

### 第3章  类与对象

##### 3.2 对象

##### 3.3 构造函数与析构函数

###### 3.3.1 构造函数

作用：对象的创建和初始化。

格式：

```c++
<类名>::<类名>(<形参表>)
{
	<函数体>
}

<类名>::<类名>()
{
}
```

特点：

- 它的函数名与类名相同。

- 它可以重载。

- 不能指定返回类型，即使是void类型也不可以。

- 它不能被显示调用，在创建对象的时候被自动调用。


###### 3.3.2 析构函数

作用：在对象消失时执行一项清理任务。

格式：

```c++
<类名>::~<类名>()
{
	<函数体>
}

<类名>::~<类名>()
{
}
```

特点：

- 析构函数的名字同类名，与构造函数名的区别在于析构函数名前加“~”，表明他的功能与构造函数的功能相反。

- 析构函数没有参数，不能重载，一个类中只能定义一个析构函数。

- 不能指定返回类型，即使是void类型也不可以。

- 析构函数在释放一个对象时候被自动调用。与构造函数不同的是，它能被显式调用，但不提倡。 

- 析构函数的调用顺序与构造函数的调用顺序相反。


###### 3.3.3 拷贝构造函数

作用：用一个已存在的对象去初始化另一个对象，为了保证所引用的对象不被修改，通常把引用参数声明为const参数。

格式：

```C++
<类名>::<类名>(const<类名>&<对象名>)
{
	<函数体>
}
```

特点：

• 

• 

• 

##### 3.4 this指针

作用：当创建一个对象时，this指针就初始化指向该对象。当某一对象调用一个成员函数时，this指针将作为一个变量自动传给该函数。

特点：

• this指针不能被显式调用。

• this指针是一个常量，不能作为赋值、递增、递减等运算的目标对象。

• 只有非静态类成员函数才拥有this指针，并通过该指针来处理对象。

• this指针只能在成员函数中使用（反元函数、全局函数不是成员函数）。

##### 3.5 子对象和堆对象

###### 3.5.1 子对象

声明：

```c++
class<X>{
		...
	<类名 1>	<子对象 1>
	<类名 2>	<子对象 2>
		...
	<类名 n>	<子对象 n>
};
```

初始化：X类的构造函数的定义形式如下

```c++
<X>::<X>(<参数表0>):<成员1>(<参数表1>),...,<成员0>(<参数表n>)
{
	...
}
```

特点：

- 对子对象的构造函数的调用顺序取决于这些子对象在类中说明的顺序，与它们在成员初始化列表中给出的顺序无关。

###### 3.5.2 堆对象

C++程序内存分区：

- 数据区(Data Area)
- 代码区(Code Area)
- 栈区(Stack Area)
- 堆区(及自有存储区)(Heap Area)

1. 使用运算符new创建堆对象

```c++
new<类型说明符>(<初始值列表>)
```

2. 使用运算符delete删除堆对象

```c++
delete<指针名>
```

3. 使用new[]创建对象数组

```c++
new<类型说明符>[<算术表达式>]
```

- 其中<算术表达式>给出数组的大小，后面不能再跟构造函数参数，所以，从对上分配对象数组，只能调用默认的构造函数，不能调用其他任何构造函数。

4. 使用delete[]删除对象数组

```c++
delete[]<指针名>
```

- 运算符delete[]必须用于有运算符new[]返回的指针。
- 对一个指针只能使用一次运算符delete[]。
- 指针名前只能用一对方括号，而不管所释放数组的维数，并且在方括号内不能写任何东西。
- 该运算符也适用于空指针。

##### 3.6 类的静态成员



### 第4章 继承机制



### 第5章 多态性和虚函数

#### 5.2 虚函数

##### 5.2.1 虚函数的作用

- 虚函数是一个成员函数，该成员函数在基类内部声明并且被派生类重新定义。

- 虚函数的定义格式：

  ```c++
  vitual <返回值类型> <函数名> (<形式参数表>)
  {
  	<函数体>
  }
  ```

- 动态联编需满足3个条件：1、类之间满足兼容规则。2、要声明虚函数。3、有成员函数来调用或是通过指针、引用来访问虚函数。

  ```c++
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
  ```

##### 5.2.2  虚函数与一般重载函数的区别

##### 5.2.3  继承虚属性

#### 5.3 成员函数中调用虚函数

- 一个基类或派生类的成员函数中可以直接调用该类等级中的虚函数。

- 在满足共有继承情况下，成员函数中调用函数将采用**动态联编**。

  ```c++
  // 【例5.8】
  // 输出结果：This is Subclass func1
  
  #include<iostream>
  
  using namespace std;
  
  class Base
  {
  public:
      virtual void func1()
      {
          cout<<"This is Base func1"<<endl;
      }
      void func2(){func1();}
  };
  class Subclass:public Base
  {
      virtual void func1()
      {
          cout<<"This is Subclass func1"<<endl;
      }
  };
  int main()
  {
      Subclass sc;
      sc.func2();
      return 0;
  }
  ```

  

#### 5.4 构造函数和析构函数中调用虚函数

- 派生类的默认构造函数将包含它的基类的默认构造函数。
- 派生类的默认析构函数将包含它的基类的默认析构函数。

#### 5.5 纯虚函数和抽象类

##### 5.5.1 纯虚函数

- 如果不能在基类中给出有意义的虚函数的实现，但又必须让基类为派生类提供一个公共界面函数。这时可以将它说明为纯虚函数，它的实现留给派生类来做。说明纯虚函数的一般形式：

```c++
virtual <返回值类型><函数名>(<形式参数表>) = 0
```

```c++
// 【例5.10】
// 用纯虚函数改写【例5.3】

#include<iostream>

const double PI = 3.14;

using namespace std;

class Figure 						 // 定义基类
{
private:
    /* data */
public:
    Figure(/* args */){};
    ~Figure(){};
    virtual double area() const = 0; // 定义为纯虚函数 
};

class Circle:public Figure      	 // 定义派生类，公有继承方式
{
private:
    double R;
public:
    Circle(double MyR) {R = MyR;};
    virtual double area() const {return R * PI * R;} // 定义为虚函数
    ~Circle() {};
};

class Rectangle:public Figure 	     // 定义派生类，公有继承方式
{
private:
    double L, W;
public:
    Rectangle(double MyL, double MyW) {L = MyL; W = MyW;};
    virtual double area() const {return L * W;}		 // 定义为虚函数
    ~Rectangle() {};
};

void function(Figure &p) 			 // 形参为基类的引用
{
    cout << p.area() << endl;
}

int main()
{ 
    Circle cir(3.0);                 // Circle 派生类对象
    cout << "Area of circle is ";
    function(cir);

    Rectangle rec(4.0, 5.0);         // Rectangle 派生类对象
    cout << "Area of rectangle is ";
    function(rec);

    return 0;
}
/********** Figure 类中的纯虚函数area()仅起到为派生类提供一个一致的接口作用 **********/
```



##### 5.5.2 抽象类

- 一个类中可以说明多个纯虚数，对于包含有纯虚函数的类被称为抽象类。

- 一个抽象类只能作为基类来派生新类，不能说明抽象类的对象。

  ```C++
  /******** 例如【5.10】 *******/
  Figure fig;            		 // 不能说明抽象类的对象
  Figure func1();        		 // 抽象类不能用作返回值
  int func2(Figure);     		 // 抽象类不能用作参数类型
  
  void function&(Figure &p);   // 可以说明指向抽象类对象的指针
  ```

#### 5.6 虚析构函数

##### 5.6.1 虚析构函数的定义和使用

```C++
// 【例5.11】
// 使用虚构函数
// 结果：
// Subclass destructor is called.    
// Base destructor is called.  

#include<iostream>

using namespace std;

class Base
{
public:
    Base() {};
    virtual ~Base() {cout << "Base destructor is called.";}
};

class Subclass:public Base
{
public:
    Subclass() {};
    ~Subclass();
};

Subclass::~Subclass() {cout << "Subclass destructor is called." << endl;}


int main()
{ 
    Base *b = new Subclass;
    delete b;  

    return 0;
}

/*********  基类的析构函数由派生类的析构函数调用  *********/  
```



##### 5.6.2 虚析构函数的必要性

#### 5.7 应用实例

- 题目：

  - 编写一个小型公司的工资管理程序。

  - 该公司主要有4类人员：经理、兼职技术人员、销售员、销售经理。
  - 要求存储并显示每类人员的编号（从10000起编号）、姓名和月薪。
  - 其中月薪的计算方法为：经理固定月薪8000元，兼职技术人员100元/小时，销售员为当月销售额的4%，销售经理保底工资5000元另加其所管部门销售额的5%。

##### 5.7.1 类的设计

![5.7.1 类的设计](E:\C language\Object-oriented\5.7.1 类的设计.png)

- 由于每类成员月薪计算方式不同，需要在派生类中进行重新定义其具体实现方式，所以在基类中将pay()(计算月薪函数)定义为纯虚函数，将display()(输出员工信息函数)定义为虚函数。

##### 5.7.2 基类Employee的定义

```C++
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
```



##### 5.7.3 兼职技术人员类Technician的定义

```C++
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
```



##### 5.7.4 销售人员类Salesman的定义

```C++
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
```



##### 5.7.5 经理类Manager的定义

```C++
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
```



##### 5.7.6 销售经理类Salesmanager的定义

```C++
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
```



##### 5.7.7 编号的初始化与主函数

```C++
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
```



### 第6章 运算符重载

- 运算符重载作用：对于同一个运算符，由于所操作的数据类型不同而具有不同的意义，因此需要运算符重载。

#### 6.1 运算符重载的规则

重载运算符必须遵循以下规则：

1. 重载运算符必须符合语言语法。

2. 不能重载对内部C++数据类型进行操作的运算符。

3. 不能创建新的运算符。

4. 不能重载下面运算符：

   . 类成员选择运算符

   

#### 6.2 运算符重载的形式

###### 6.2.1 用成员函数重载运算符

- 用成员函数重载运算符的原型：

  ```C++
  <返回值类型> operator <运算符> (<形式参数表>)
  ```

  

#### 6.3 单目运算符重载

#### 6.4 赋值运算符重载

#### 6.5 特殊运算符重载

#### 6.6 类类型转换运算符重载

#### 6.7 应用实例

### 第7章 模板

#### 7.1 模板的概念

##### 7.1.1 强类型的严格性与灵活性

强类型的程序设计迫使程序员为逻辑结构相同而具体数据类型不同的对象编写模式一致的代码，但因无法抽取其中的共性，所以不利于程序的扩充和维护。

##### 7.1.2 解决冲突的途径

3种实现方法：

1. 利用宏函数（不提倡）。
2. 为各种类型都重载这一函数。
3. 放松类型检查。

##### 7.1.3 模板的概念

模板是一种参数化多态性的工具，可以为逻辑功能相同而类型不同的程序提供代码共享机制。

- 在C++中，模板被分为函数模板和类模板。
- 带类属参数的函数成为函数模板，带类属参数的类被称为类模板。

#### 7.2 函数模板

##### 7.2.1 函数模板的定义

```c++
template <模板参数表>         // template 为定义模板的关键字
<返回值类型><函数名>(<参数表>)  // <模板参数表>中包含一个或多个用逗号分开的模板参数项，每一项有保留字typename开始。
{
	<函数体>
}
```

【例7.1】 定义函数模板求两个数中的较大值

```C++
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}
```

- <参数表>中至少有一个形参的类型必须用<模板参数表>中的形参定义的。
- 在<模板参数表>中的每个模板参数都必须在<参数表>中得到使用，即作为形参的类型使用。

##### 7.2.2 函数模板的实例化

【例7.2】 利用例7.1中的函数模板求两个数中的较大值。

```C++
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
```

- 函数模板的声明和定义必须是全局作用域，而且模板不能被声明成类的成员函数。
- 编译器不会为没有用到的任何类型生成相应的模板函数。
- 无论为一种类型使用了多少次函数模板，都只为该类型生成一次模板函数。

##### 7.2.3 函数模板的重载

函数模板有多种重载方式，可以定义同名的函数模板，提供不同的参数和实现；也可以用其他非模板函数重载。

1. 函数模板的重载

   【例7.3】 利用例7.2中的函数模板求数组数中的最大值。

   ```C++
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
   ```

   

2. 用普通函数重载函数模板

   问题：函数模板实例化时，实际参数类型将替换函数模板参数。虽然这种参数替换具有类型检查功能，但却没有普通传值参数的类型转换机制。

   解决方式：用非函数模板重载一个同名的函数模板。

   【例7.4】 示例普通函数重载函数模板。

   ```C++
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
   ```

   

3. 用特定函数重载函数模板

   【例7.5】修改例7.4，增加比较字符数组的功能。

   ```C++
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
   
   ```

   编译器通过匹配过程确定调用哪个函数，其匹配顺序：

   1. 首先寻找和使用最符合函数名和参数类型的特定模板函数，若找到则调用它。
   2. 其次寻找一个函数模板，将其实例化产生一个匹配的模板函数，若找到则调用它。
   3. 再次寻找可以通过类型转换进行参数匹配的重载函数，若找到则调用它。
   4. 若按以上顺序均未能找到匹配函数，则这个调用是错误的。

#### 7.3 类模板

##### 7.3.1 类模板的定义

类模板的定义格式：

```C++
template <模板参数表>  // <模板参数表>中包含一个或多个用逗号分开的类型，参数项可以包含数据类型，
class <类模板名>      // 也可以包含类属性类型：如果是类属类型，则需加前缀class或typename 
{
	<类成员声明>
}
```



##### 7.3.2 类模板的实例化

##### 7.3.3 使用函数类型参数的类模板

##### 7.3.4 使用默认参数的类模板

#### 7.4 标准模板库STL

##### 7.4.1 容器

1. 容器的分类
2. 容器的借口
3. 顺序容器
4. 关联容器

【例7.9】示例STL容器的使用。

```C++
#include <iostream>
#include <vector> // 包含向量容器头文件

using namespace std;

int main()
{
    int i;
    vector<int> nums; // 整形向量，长度为0
    nums.insert(nums.begin(), -99); // 在向量第1个位置插入-99
    nums.insert(nums.begin(), 4); // 在向量第1个位置插入4
    nums.insert(nums.end(), 50); // 在向量末尾插入50

    for(i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";  // 依次输出向量中所有元素：4 -99 50
    cout << endl;

    nums.erase(nums.begin()); // 删除向量中第1个元素4
    nums.erase(nums.begin()); // 删除向量中第1个元素-99

    for(i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";  // 依次输出向量中所有元素：50
    cout << endl;

    return 0;
}
/********* 运行结果：**********/
/********* 4 -99 50 **********/
/********* 50       **********/
```



##### 7.4.2 迭代器

1. 迭代器的分类

2. 迭代器的使用

   【例7.10】正向、逆向输出双向链表中所有元素，示例STL迭代器的使用。

   ```C++
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
   ```

   

##### 7.4.3 算法

#### 7.5 应用实例

##### 7.5.1 通过自定义类模板对双向链表进行基本操作

##### 7.5.2 通过STL对双向链表进行基本操作

### 第8章 I/O 流类库

##### 8.1 概述

##### 8.2 格式化输入输出

##### 8.3 重载六的插入符合提取符

##### 8.4 I/O常用成员函数

##### 8.5 流的错误处理

##### 8.6 文件流操作

##### 8.7 应用实例

#### 第9章 异常处理

#### 第10章 综合应用实例







