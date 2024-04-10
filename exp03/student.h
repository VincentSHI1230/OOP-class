#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student {
public:
    Student(std::string name, std::string stu_id,
        char gender = '\0', int age = -1,
        std::string class_name = "",
        double grade_comp = -1, double grade_eng = -1);
    void set(int key, std::string value);
    void set(int key, char value);
    void set(int key, int value);
    void set(int key, double value);
    void get(int key, std::string& value) const;
    void get(int key, char& value) const;
    void get(int key, int& value) const;
    void get(int key, double& value) const;
    std::string name() const;
    double avg() const;

protected:
    std::string _name;
    std::string _stu_id;
    char _gender;
    int _age;
    std::string _class_name;
    double _grade_comp;
    double _grade_eng;
private:
    std::string _gender_str;
    void _upd_gs();
};

#define NAME 0x0
#define STU_ID 0x1
#define GENDER 0x2
#define AGE 0x3
#define CLASS_NAME 0x4
#define GRADE_COMP 0x5
#define GRADE_ENG 0x6

#define STR_LIKE \
    case NAME:   \
    case STU_ID: \
    case CLASS_NAME
#define TEXT_LIKE \
    STR_LIKE:     \
    case GENDER
#define NUM_LIKE     \
    case AGE:        \
    case GRADE_COMP: \
    case GRADE_ENG

#endif // STUDENT_H
