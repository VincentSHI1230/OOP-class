#include "interview.h"

int main()
{
    // 在主函数中创建 interviewee 对象并初始化
    Interviewee i("Alice", 25, "Software Engineer");
    // 使用友元函数对对象信息进行输出
    showinfo(i);
    // 使用友元类成员函数对对象信息进行输出
    Interviewer iv;
    iv.showinfo(i);
    return 0;
}
