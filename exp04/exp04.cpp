#include "line.h"
#include <iostream>

int main()
{
    std::cout << "=========== 实现部分 ===========" << std::endl;
    int x1, y1, x2, y2;
    std::cout << "请输入坐标 (x1, y1, x2, y2): ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1);
    Point p2(x2, y2);
    Line l(p1, p2);
    l.print();
    std::cout << std::endl;

#ifdef EXPAND
    std::cout << "=========== 拓展部分 ===========" << std::endl;
    Line expand_l;
    std::cout << "请输入坐标 (x1, y1, x2, y2): ";
    std::cin >> expand_l;
    std::cout << expand_l << std::endl;
#endif // EXPAND

    return 0;
}
