/*
 *  encoding: utf-8
 *  author: 史胤隆
 *  date: 2024/3/13
 */

#include <iostream>
using namespace std;

void opt_value()
{
    // 通过程序求以下表达式的值并输出到屏幕上。
    cout << "2004 / 3           =   " << 2004 / 3 << endl;
    cout << "2004 % 3           =   " << 2004 % 3 << endl;
    cout << "20 / 7             =   " << 20 / 7 << endl;
    int a = 18;
    cout << "a = 18, a * 3      =   " << a * 3 << endl;
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    cout << "==== WHEN a1 = 1, a2 = 2, a3 = 3 ====" << endl;
    cout << "a1||a2+a3&&a3-a1   =   " << (a1 || a2 + a3 && a3 - a1) << endl;
    cout << "a1+a2>a3&&a1==a2   =   " << (a1 + a2 > a3 && a1 == a2) << endl;
    cout << "3<8&&8>18          =   " << (3 < 8 && 8 > 18) << endl;
    cout << "!(8>3)             =   " << !(8 > 3) << endl;
}

void comp_struct()
{
    // 定义一个计算器结构体，当输入两个整数及运算符后，可以进行算术四则运算。
    struct calculator {
        int a;
        char op;
        int b;
        int result;
    };
    calculator cal {};
    cout << "请按照\"a op b\"的格式输入两个整数和一个运算符: ";
    cin >> cal.a >> cal.op >> cal.b;
    switch (cal.op) {
    case '+':
        cal.result = cal.a + cal.b;
        break;
    case '-':
        cal.result = cal.a - cal.b;
        break;
    case '*':
        cal.result = cal.a * cal.b;
        break;
    case '/':
        if (cal.b == 0) {
            cout << "除数不能为0! " << endl;
            return;
        }
        cal.result = cal.a / cal.b;
        break;
    default:
        cout << "运算符输入错误! " << endl;
        return;
    }
    cout << "结果为: " << cal.result << endl;
}

void printp()
{
    // 用循环语句编程打印如下矩阵或图案
    cout << "图案1: " << endl;
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << "    ";
        for (int j = i; j < i + 6; j++) {
            cout << j % 6 << " ";
        }
        cout << endl;
    }
    cout << "图案2: " << endl;
    string patt_a = "  ";
    string patt_b = "# ";
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << patt_a;
        }
        for (int j = 0; j < 11 - 2 * i; j++) {
            cout << patt_b;
        }
        // 由于 patt_a 在本题中为空格，所以不需要输出
        // for(int j = 0; j < i; j++) {
        //     cout << patt_a;
        // }
        cout << endl;
    }
}

int main()
{
    cout << endl
         << "实验一 | 练习1" << endl;
    opt_value();
    cout << endl
         << "实验一 | 练习2 - 将重复检验 5 次" << endl;
    for (int i = 0; i < 5; i++) {
        comp_struct();
    }
    cout << endl
         << "实验一 | 练习3" << endl;
    printp();
    return 0;
}
