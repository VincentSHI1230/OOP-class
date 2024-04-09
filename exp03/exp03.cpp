#include "student.h"
#include <iostream>

int main()
{
    // ================ 测试部分 ================
    Student test("田所浩二", "0114514", 'M');
    test.set(AGE, 24);
    test.set(CLASS_NAME, "下北泽19班");
    test.set(GRADE_COMP, 11.4);
    test.set(GRADE_ENG, 51.4);
    int a;
    test.get(AGE, a);
    std::cout << "(测试) " << test.name() << "的年龄: " << a << std::endl;
    char g;
    test.get(GENDER, g);
    std::cout << "(测试) " << test.name() << "的性别: " << g << std::endl;
    const char* cn;
    test.get(CLASS_NAME, cn);
    std::cout << "(测试) " << test.name() << "的班级: " << cn << std::endl;
    double gc;
    test.get(GRADE_COMP, gc);
    std::cout << "(测试) " << test.name() << "的计算机成绩: " << gc << std::endl;
    int ge;
    test.get(GRADE_ENG, ge);
    std::cout << "(测试 | int) " << test.name() << "的英语成绩: " << ge << std::endl;
    std::cout << "(测试) " << test.name() << "的平均成绩: " << test.avg() << std::endl;
    // ================ 执行部分 ================
    Student zhang_yy("张伊一", "2012101", 'F', 20, "信息121", 89, 95);
    Student li_qq("李柒柒", "2012102", 'F', 20, "信息122", 90, 95);
    std::cout << zhang_yy.name() << "的平均成绩: " << zhang_yy.avg() << std::endl;
    std::cout << li_qq.name() << "的平均成绩: " << li_qq.avg() << std::endl;
    return 0;
}
