#include "student.h"
#include <iostream>

Student::Student(const char* name, const char* stu_id)
{
    _name = name;
    _stu_id = stu_id;
    _gender = '-';
    _age = 0;
    _class_name = "";
    _grade_comp = 0;
    _grade_eng = 0;
}

Student::Student(const char* name, const char* stu_id,
    char gender, int age, const char* class_name,
    double grade_comp, double grade_eng)
{
    _name = name;
    _stu_id = stu_id;
    _gender = gender;
    _age = age;
    _class_name = class_name;
    _grade_comp = grade_comp;
    _grade_eng = grade_eng;
}

void Student::set(int key, const char* value)
{
    switch (key) {
    case NAME:
        _name = value;
        break;
    case STU_ID:
        _stu_id = value;
        break;
    case CLASS_NAME:
        _class_name = value;
        break;
    CHAR_LIKE:
    INT_LIKE:
    DOUBLE_LIKE:
        std::cerr << "set 格式不匹配" << std::endl;
        break;
    default:
        std::cerr << "set key 不存在" << std::endl;
    }
}

void Student::set(int key, char value)
{
    switch (key) {
    case GENDER:
        _gender = value;
        break;
    CHAR_P_LIKE:
    INT_LIKE:
    DOUBLE_LIKE:
        std::cerr << "set 格式不匹配" << std::endl;
        break;
    default:
        std::cerr << "set key 不存在" << std::endl;
    }
}

void Student::set(int key, int value)
{
    switch (key) {
    case AGE:
        _age = value;
        break;
    case GRADE_COMP:
        _grade_comp = (double)value;
        break;
    case GRADE_ENG:
        _grade_eng = (double)value;
        break;
    CHAR_P_LIKE:
    CHAR_LIKE:
        std::cerr << "set 格式不匹配" << std::endl;
        break;
    default:
        std::cerr << "set key 不存在" << std::endl;
    }
}

void Student::set(int key, double value)
{
    switch (key) {
    case AGE:
        _age = (int)value;
        break;
    case GRADE_COMP:
        _grade_comp = value;
        break;
    case GRADE_ENG:
        _grade_eng = value;
        break;
    CHAR_P_LIKE:
    CHAR_LIKE:
        std::cerr << "set 格式不匹配" << std::endl;
        break;
    default:
        std::cerr << "set key 不存在" << std::endl;
    }
}

void Student::get(int key, const char*& value) const
{
    switch (key) {
    case NAME:
        value = _name;
        break;
    case STU_ID:
        value = _stu_id;
        break;
    case CLASS_NAME:
        value = _class_name;
        break;
    CHAR_LIKE:
    INT_LIKE:
    DOUBLE_LIKE:
        std::cerr << "get 格式不匹配" << std::endl;
        break;
    default:
        std::cerr << "get key 不存在" << std::endl;
    }
}

void Student::get(int key, char& value) const
{
    switch (key) {
    case GENDER:
        value = _gender;
        break;
    CHAR_P_LIKE:
    INT_LIKE:
    DOUBLE_LIKE:
        std::cerr << "get 格式不匹配" << std::endl;
        break;
    default:
        std::cerr << "get key 不存在" << std::endl;
    }
}

void Student::get(int key, int& value) const
{
    switch (key) {
    case AGE:
        value = _age;
        break;
    case GRADE_COMP:
        value = (int)_grade_comp;
        break;
    case GRADE_ENG:
        value = (int)_grade_eng;
        break;
    CHAR_P_LIKE:
    CHAR_LIKE:
        std::cerr << "get 格式不匹配" << std::endl;
        break;
    default:
        std::cerr << "get key 不存在" << std::endl;
    }
}

void Student::get(int key, double& value) const
{
    switch (key) {
    case AGE:
        value = (double)_age;
        break;
    case GRADE_COMP:
        value = _grade_comp;
        break;
    case GRADE_ENG:
        value = _grade_eng;
        break;
    CHAR_P_LIKE:
    CHAR_LIKE:
        std::cerr << "get 格式不匹配" << std::endl;
        break;
    default:
        std::cerr << "get key 不存在" << std::endl;
    }
}

double Student::avg() const
{
    return (_grade_comp + _grade_eng) / 2;
}
