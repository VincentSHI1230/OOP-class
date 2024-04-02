/*
 * 写一个程序将24小时制的时间转换为12小时制的时间，例如将14:25转为2:25 P.M. 输入为两个整型的数。
 * 该程序要设计成三个函数：输入，转换和输出，用字符’A’表示A.M.，用字符’P’表示P.M.
 * 函数声明如下：
 * void input(int&hours24,int&minutes);
 * void convert(int&hours,char&ampm);
 * void output(int hours,int minutes,char ampm);
 */

#include <iostream>

#define CHECK

void input(int& hours24, int& minutes);
void convert(int& hours, char& ampm);
void output(int hours, int minutes, char ampm);

int main()
{
    int hour, min;
    char ampm;
    input(hour, min);
    convert(hour, ampm);
    output(hour, min, ampm);
    return 0;
}

void input(int& hours24, int& minutes)
{
    //  [out]   int&    hours24
    //  [out]   int&    minutes
    std::cout << "请输入 24 小时制时间 (H:m): ";
    char _;
    std::cin >> hours24 >> _ >> minutes;
#ifdef CHECK
    if (hours24 < 0 || hours24 > 23 || minutes < 0 || minutes > 59 || _ != ':') {
        std::cerr << "输入错误!" << std::endl;
        exit(1);
    }
#endif
}

void convert(int& hours, char& ampm)
{
    //  [io]    int&    hours
    //  [out]   char&   ampm
    ampm = hours < 12 ? 'A' : 'P';
    hours = (hours %= 12) == 0 ? 12 : hours;
}

void output(int hours, int minutes, char ampm)
{
    //          int     hours
    //          int     minutes
    //          char    ampm
    std::cout << "12 小时制时间 (h:m tt): " << hours << ":" << minutes << " " << ampm << ".M." << std::endl;
}
