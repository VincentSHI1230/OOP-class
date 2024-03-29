/*
 * 编一个程序，用同一个函数名对圆、矩形、梯形求面积，参数自行设置，要求所有输入输出在主函数内进行。
 */

#include <iostream>
using namespace std;

#define PI 3.14

inline double area(double r);
inline double area(double l, double w);
inline double area(double a, double b, double h);

int main()
{
    int choice;
    double v1, v2, v3;
    cout << "你希望计算 (1.圆 / 2.矩形 / 3.梯形): ";
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "请输入\n\t半径: ";
        cin >> v1;
        cout << "圆的面积为: " << area(v1) << endl;
        break;
    case 2:
        cout << "请输入\n\t长: ";
        cin >> v1;
        cout << "\t宽: ";
        cin >> v2;
        cout << "矩形的面积为: " << area(v1, v2) << endl;
        break;
    case 3:
        cout << "请输入\n\t上底: ";
        cin >> v1;
        cout << "\t下底: ";
        cin >> v2;
        cout << "\t高: ";
        cin >> v3;
        cout << "梯形的面积为: " << area(v1, v2, v3) << endl;
        break;
    default:
        cerr << "输入错误!" << endl;
        break;
    }
    return 0;
}

inline double area(double r)
{
    return PI * r * r;
}

inline double area(double l, double w)
{
    return l * w;
}

inline double area(double a, double b, double h)
{
    return (a + b) * h / 2;
}
