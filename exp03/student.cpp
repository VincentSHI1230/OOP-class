#include "student.h"
#include <iostream>
#include <string>

Student::Student(std::string name, std::string stu_id,
    char gender, int age, std::string class_name,
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

void Student::set(int key, std::string value)
{
    switch (key) {
    case NAME:
        _name = value;
        break;
    case STU_ID:
        _stu_id = value;
        break;
    case GENDER:
        _gender = value[0];
        _upd_gs();
        break;
    case CLASS_NAME:
        _class_name = value;
        break;
    NUM_LIKE:
        std::cerr << "Student::set(int key, std::string value)\n\t格式不匹配"
                  << std::endl;
        break;
    default:
        std::cerr << "Student::set(int key, std::string value)\n\tkey 不存在"
                  << std::endl;
    }
}

void Student::set(int key, char value)
{
    switch (key) {
    case GENDER:
        _gender = value;
        _upd_gs();
        break;
#ifdef ALLOW_INT_ID
    case STU_ID:
#endif
    STR_LIKE:
    NUM_LIKE:
        std::cerr << "Student::set(int key, char value)\n\t格式不匹配"
                  << std::endl;
        break;
    default:
        std::cerr << "Student::set(int key, char value)\n\tkey 不存在"
                  << std::endl;
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
#ifdef ALLOW_INT_ID
    case STU_ID:
        _stu_id = std::to_string(value);
        break;
#endif
    TEXT_LIKE:
        std::cerr << "Student::set(int key, int value)\n\t格式不匹配"
                  << std::endl;
        break;
    default:
        std::cerr << "Student::set(int key, int value)\n\tkey 不存在"
                  << std::endl;
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
#ifdef ALLOW_INT_ID
    case STU_ID:
#endif
    TEXT_LIKE:
        std::cerr << "Student::set(int key, double value)\n\t格式不匹配"
                  << std::endl;
        break;
    default:
        std::cerr << "Student::set(int key, double value)\n\tkey 不存在"
                  << std::endl;
    }
}

void Student::get(int key, std::string& value) const
{
    switch (key) {
    case NAME:
        value = _name;
        break;
    case STU_ID:
        value = _stu_id;
        break;
    case GENDER:
        value = _gender_str;
        break;
    case CLASS_NAME:
        value = _class_name;
        break;
    NUM_LIKE:
        std::cerr << "Student::get(int key, std::string& value) const\n\t格式不匹配"
                  << std::endl;
        break;
    default:
        std::cerr << "Student::get(int key, std::string& value) const\n\tkey 不存在"
                  << std::endl;
    }
}

void Student::get(int key, char& value) const
{
    switch (key) {
    case GENDER:
        value = _gender;
        break;
#ifdef ALLOW_INT_ID
    case STU_ID:
#endif
    STR_LIKE:
    NUM_LIKE:
        std::cerr << "Student::get(int key, char& value) const\n\t格式不匹配"
                  << std::endl;
        break;
    default:
        std::cerr << "Student::get(int key, char& value) const\n\tkey 不存在"
                  << std::endl;
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
#ifdef ALLOW_INT_ID
    case STU_ID:
        value = std::stoi(_stu_id);
        break;
#endif
    TEXT_LIKE:
        std::cerr << "Student::get(int key, int& value) const\n\t格式不匹配"
                  << std::endl;
        break;
    default:
        std::cerr << "Student::get(int key, int& value) const\n\tkey 不存在"
                  << std::endl;
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
#ifdef ALLOW_INT_ID
    case STU_ID:
#endif
    TEXT_LIKE:
        std::cerr << "Student::get(int key, double& value) const\n\t格式不匹配"
                  << std::endl;
        break;
    default:
        std::cerr << "Student::get(int key, double& value) const\n\tkey 不存在"
                  << std::endl;
    }
}

std::string Student::name() const
{
    return _name;
}

double Student::avg() const
{
    return (_grade_comp + _grade_eng) / 2;
}

void Student::_upd_gs()
{
    switch (_gender) {
    case 'M':
        _gender_str = "男";
        break;
    case 'F':
        _gender_str = "女";
        break;
    default:
        char g[2] = { _gender, '\0' };
        std::string gs(g);
        _gender_str = "未知 (" + gs + ")";
    }
}