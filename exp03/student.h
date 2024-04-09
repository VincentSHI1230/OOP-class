#ifndef STUDENT_H
#define STUDENT_H

class Student {
public:
    Student(const char* name, const char* stu_id,
        char gender = '\0', int age = -1, const char* class_name = "",
        double grade_comp = -1, double grade_eng = -1);
    void set(int key, const char* value);
    void set(int key, char value);
    void set(int key, int value);
    void set(int key, double value);
    void get(int key, const char*& value) const;
    void get(int key, char& value) const;
    void get(int key, int& value) const;
    void get(int key, double& value) const;
    const char* name() const;
    double avg() const;

protected:
    const char* _name;
    const char* _stu_id;
    char _gender;
    int _age;
    const char* _class_name;
    double _grade_comp;
    double _grade_eng;
};

#define NAME 0x0
#define STU_ID 0x1
#define GENDER 0x2
#define AGE 0x3
#define CLASS_NAME 0x4
#define GRADE_COMP 0x5
#define GRADE_ENG 0x6

#define CHAR_P_LIKE \
    case NAME:      \
    case STU_ID:    \
    case CLASS_NAME
#define CHAR_LIKE case GENDER
#define INT_LIKE case AGE
#define DOUBLE_LIKE  \
    case GRADE_COMP: \
    case GRADE_ENG

#endif // STUDENT_H
