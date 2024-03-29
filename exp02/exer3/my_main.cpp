#include "my_area.h"

int main()
{
    int choice;
    double v1, v2;
    cout << "你希望计算 (1.圆 / 2.矩形): ";
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "请输入\n\t半径: ";
        cin >> v1;
        cout << "圆的面积为: " << circle(v1) << endl;
        break;
    case 2:
        cout << "请输入\n\t长: ";
        cin >> v1;
        cout << "\t宽: ";
        cin >> v2;
        cout << "矩形的面积为: " << rect(v1, v2) << endl;
        break;
    default:
        cerr << "输入错误!" << endl;
    }
    return 0;
}
