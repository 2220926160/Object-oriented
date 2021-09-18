## 面向对象程序设计教程（C++语言描述）

### 第1章 面向对象程序设计概论

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

• 它的函数名图类名名相同。

• 它可以重载。

• 不能指定返回类型，即使是void类型也不可以。

•它不能被显示调用，在创建对象的时候被自动调用。

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

• 析构函数的名字同类名，与构造函数名的区别在于析构函数名前加“~”，表明他的功能与构造函数的功能相反。

• 析构函数没有参数，不能重载，一个类中只能定义一个析构函数。

• 不能指定返回类型，即使是void类型也不可以。

• 析构函数在释放一个对象时候被自动调用。与构造函数不同的是，它能被显式调用，但不提倡。 

注：析构函数的调用顺序与构造函数的调用顺序相反。



#### 第2章 从C到C++



#### 第3章 类与对象


