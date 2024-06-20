# 实验 6 - C++ 程序设计之继承与派生篇

> 智能 212 史胤隆 2006010529  
> 指导老师：杨伟杰

## 一、实验目的

1. 熟悉 Visual C++ 6.0 开发环境下的源程序编辑、调试等功能。
1. 通过程序设计学习类的继承与派生

## 二、实验内容及结果

### 练习 1

**编程实现：**

-   定义员工类 Employee，此类具有私有的数据成员用以表示员工的姓名，工号和薪资。并有带参构造函数用于相关数据成员的初始化，另外，由一个公有成员函数 show 用于输出员工的所有数据信息。
-   在 Employee 类上派生出销售经理类 Salemanager，该类具有一个新的属性 - 销售业绩；并有带参构造函数用于相关数据成员的初始化，另外，由一个公有成员函数 show 用于输出销售经理的所有信息。
-   在 Employee 类上派生出技术工人类 Technician，该类具有一个新的属性 - 工作时间；并有带参构造函数用于相关数据成员的初始化，另外，由一个公有成员函数 show 用于输出技术工人的所有信息。
-   定义 Salemanager 和 Technician 对象，用于表示某两个员工，并将相关信息进行输出。

### 练习 2

**类、日期类、时间日期类**

```cpp
#include <iostream>
using namespace std;

class CTimeType // 定义时间类
{
    int hour, minute, second; // 成员变量
public:
    CTimeType(int h = 12, int m = 0, int s = 0) // 构造函数
    {
        hour = h;
        minute = m;
        second = s;
    }
    void display() // 成员函数，输出时间
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
    void setTime(int h, int m, int s) // 成员函数，设置时间
    {
        hour = h;
        minute = m;
        second = s;
    }
};

class CDateType // 日期类
{
    int month, day, year;

public:
    CDateType(int mon = 1, int d = 1, int y = 2008) // 构造函数
    {
        month = mon;
        day = d;
        year = y;
    }
    void display() // 成员函数，输出日期
    {
        cout << month << "/" << day << "/" << year << endl;
    }
    void SetDate(int mon, int d, int y) // 成员函数，设置日期
    {
        month = mon;
        day = d;
        year = y;
    }
};

```

在日期类和时间类的基础上，共有继承产生新的时间日期类 CDateTimeType 。请根据如下主函数给出时间日期类的实现。

```cpp
int main()
{
    cout << "类的多重继承演示" << endl;
    CDateTimeType da(1, 1, 2015, 18, 35, 0); // 直接使用CDTimeType构造函数设置日期时间
    cout << "调用CDTimeType设定的初始日期、时间为：" << endl;
    da.display(); // 显示时间日期
    da.SetDate(7, 6, 2015); // 调用基类的成员函数设置日期
    da.setTime(18, 36, 0); // 调用基类的成员函数设置时间
    cout << "显示修改后的日期和时间" << endl;
    da.display();
    return 0;
}

```
