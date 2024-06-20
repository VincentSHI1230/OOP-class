#include "interview.h"
#include <iostream>
#include <string>

Interviewee::Interviewee(std::string name, int age, std::string job)
{
    _name = name;
    _age = age;
    _job = job;
}

void Interviewer::showinfo(Interviewee& i)
{
    std::cout << i._name << ", age: " << i._age << ", applied job " << i._job << "." << std::endl;
}

void showinfo(Interviewee& i)
{
    std::cout << i._name << ", age: " << i._age << ", applied job " << i._job << "." << std::endl;
}
