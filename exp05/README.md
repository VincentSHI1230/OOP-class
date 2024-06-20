# 实验 5 - C++ 程序设计之类与对象篇

> 智能 212 史胤隆 2006010529  
> 指导老师：杨伟杰



## 一、实验目的

1. 熟悉 Visual C++ 6.0 开发环境下的源程序编辑、调试等功能。
1. 通过程序设计学习类与对象的声明、定义，成员的访问
1. 通过程序设计学习类的友元函数的声明、定义及调用方式



## 二、实验内容及结果

**定义一个应试人员类 interviewee，具有私有属性：姓名、年龄、应聘职位。相关属性由带参构造函数进行初始化；**

（1）定义其友元函数 showinfo 将该类对象的相关信息进行输出。  
（2）定义其友元类 inerviewer，具有成员函数 showinfo，用于将 interviewee 的对象信息进行输出。  
（3）在主函数中创建 interviewee 对象并初始化，使用友元函数和友元类成员函数对 interviewee 对象信息进行输出

本练习考察了类的友元函数和友元类的使用。主函数及其运行结果如下：

```cpp
// 在主函数中创建 interviewee 对象并初始化
Interviewee i("Alice", 25, "Software Engineer");
// 使用友元函数对对象信息进行输出
showinfo(i);
// 使用友元类成员函数对对象信息进行输出
Interviewer iv;
iv.showinfo(i);

```

```log
Alice, age: 25, applied job Software Engineer.
Alice, age: 25, applied job Software Engineer.

```
