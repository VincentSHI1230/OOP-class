#include "line.h"
#include <cfloat>
#include <iostream>

Point::Point(double x, double y)
{
    _x = x;
    _y = y;
}

double Point::x() const { return _x; }
double Point::y() const { return _y; }

void Point::print() const
{
    std::cout << "(" << _x << ", " << _y << ")";
}

Line::Line(Point p1, Point p2)
{
    _p1 = p1;
    _p2 = p2;
    _k = p1.x() == p2.x() ? DBL_MAX : (p2.y() - p1.y()) / (p2.x() - p1.x());
}

void Line::print() const
{
    std::cout << "由 ";
    _p1.print();
    std::cout << " 和 ";
    _p2.print();
    std::cout << " 确定的直线, 斜率";
    if (_k == DBL_MAX)
        std::cout << "不存在.";
    else
        std::cout << "为 " << _k << ".";
}

#ifdef EXPAND

std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p._x >> p._y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p)
{
    os << "(" << p._x << ", " << p._y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Line& l)
{
    is >> l._p1 >> l._p2;
    l._k = l._p1.x() == l._p2.x() ? DBL_MAX : (l._p2.y() - l._p1.y()) / (l._p2.x() - l._p1.x());
    return is;
}

std::ostream& operator<<(std::ostream& os, Line& l)
{
    os << "由 " << l._p1 << " 和 " << l._p2 << " 确定的直线, 斜率";
    if (l._k == DBL_MAX)
        return os << "不存在.";
    else
        return os << "为 " << l._k << ".";
}

#endif // EXPAND
