#include "student.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "================ 测试部分 ================" << std::endl;
    std::string name, stu_id, class_name;
    char gender;
    int age, grade_comp;
#ifdef ALLOW_INT_ID
    int stu_id_int;
#endif
    double grade_eng;
    std::cout << "name: ";
    std::cin >> name;
    std::cout << "stu_id: ";
    std::cin >> stu_id;
    std::cout << "gender: ";
    std::cin >> gender;
    Student test(name, stu_id, gender);
    std::cout << "(re) gender: ";
    std::cin >> gender;
    test.set(GENDER, gender);
    std::string gender_str;
    std::cout << "(re | str) gender: ";
    std::cin >> gender_str;
    test.set(GENDER, gender_str);
    std::cout << "age: ";
    std::cin >> age;
    test.set(AGE, age);
    std::cout << "class_name: ";
    std::cin >> class_name;
    test.set(CLASS_NAME, "class_name");
    std::cout << "(int) grade_comp: ";
    std::cin >> grade_comp;
    test.set(GRADE_COMP, grade_comp);
    std::cout << "(double) grade_eng: ";
    std::cin >> grade_eng;
    test.set(GRADE_ENG, grade_eng);
#ifdef ALLOW_INT_ID
    test.get(STU_ID, stu_id_int);
    std::cout << "(int) " << test.name() << "的学号: " << stu_id_int << std::endl;
#endif
    test.get(AGE, age);
    std::cout << test.name() << "的年龄: " << age << std::endl;
    test.get(GENDER, gender);
    std::cout << test.name() << "的性别: " << gender << std::endl;
    std::string g_2;
    test.get(GENDER, g_2);
    std::cout << "(str) " << test.name() << "的性别: " << g_2 << std::endl;
    std::string cn;
    test.get(CLASS_NAME, cn);
    std::cout << test.name() << "的班级: " << cn << std::endl;
    double gc;
    test.get(GRADE_COMP, gc);
    std::cout << "(int) " << test.name() << "的计算机成绩: " << gc << std::endl;
    int ge;
    test.get(GRADE_ENG, ge);
    std::cout << test.name() << "的英语成绩: " << ge << std::endl;
    std::cout << test.name() << "的平均成绩: " << test.avg() << std::endl;
    std::cout << "================ 任务部分 ================" << std::endl;
    Student zhang_yy("张伊一", "2012101", 'F', 20, "信息121", 89, 95);
    Student li_qq("李柒柒", "2012102", 'F', 20, "信息122", 90, 95);
    std::cout << zhang_yy.name() << "的平均成绩: " << zhang_yy.avg() << std::endl;
    std::cout << li_qq.name() << "的平均成绩: " << li_qq.avg() << std::endl;
    return 0;
}
