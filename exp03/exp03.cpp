#include "student.h"
#include <iostream>

int main()
{
    Student zhang_yy("张伊一", "2012101", 'F', 20, "信息121", 89, 95);
    Student li_qq("李柒柒", "2012102", 'F', 20, "信息122", 90, 95);
    Student test("测试", "2012103");
    std::cout << "张伊一的平均成绩: " << zhang_yy.avg() << std::endl;
    std::cout << "李柒柒的平均成绩: " << li_qq.avg() << std::endl;
    test.set(GENDER, 'M');
    test.set(AGE, 21);
    test.set(CLASS_NAME, "信息123");
    test.set(GRADE_COMP, 90);
    test.set(GRADE_ENG, 95.0);
    std::cout << "测试的平均成绩: " << test.avg() << std::endl;
    int a;
    test.get(AGE, a);
    std::cout << "测试的年龄: " << a << std::endl;
    char g;
    test.get(GENDER, g);
    std::cout << "测试的性别: " << g << std::endl;
    const char* cn;
    test.get(CLASS_NAME, cn);
    std::cout << "测试的班级: " << cn << std::endl;
    int gc;
    test.get(GRADE_COMP, gc);
    std::cout << "测试的计算机成绩: " << gc << std::endl;
    double ge;
    test.get(GRADE_ENG, ge);
    std::cout << "测试的英语成绩: " << ge << std::endl;
    return 0;
}
