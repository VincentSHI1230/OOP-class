#ifndef INTERVIEW_H
#define INTERVIEW_H

#include <string>

// 定义一个应试人员类 interviewee
class Interviewee {
    friend void showinfo(Interviewee& i); // 定义其友元函数 showinfo
    friend class Interviewer; // 定义其友元类 inerviewer

public:
    // 相关属性由带参构造函数进行初始化
    Interviewee(std::string name, int age, std::string job);

private: // 具有私有属性: 姓名, 年龄, 应聘职位
    std::string _name;
    int _age;
    std::string _job;
};

class Interviewer {
public:
    // 成员函数 showinfo 用于将 interviewee 的对象信息进行输出
    void showinfo(Interviewee& i);
};

#endif // INTERVIEW_H
