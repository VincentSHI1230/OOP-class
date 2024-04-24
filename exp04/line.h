#ifndef LINE_H
#define LINE_H

#define EXPAND

#include <iostream>

class Point {
#ifdef EXPAND
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, Point& p);
#endif // EXPAND

public:
    Point(double x, double y);
    Point() = default;
    double x() const;
    double y() const;
    void print() const;

private:
    double _x {};
    double _y {};
};

class Line {
#ifdef EXPAND
    friend std::istream& operator>>(std::istream& is, Line& l);
    friend std::ostream& operator<<(std::ostream& os, Line& l);
#endif // EXPAND

public:
    Line(Point p1, Point p2);
    Line() = default;
    void print() const;

private:
    Point _p1 {};
    Point _p2 {};
    double _k {};
};

#ifdef EXPAND
std::istream& operator>>(std::istream& is, Point& p);
std::ostream& operator<<(std::ostream& os, Point& p);
std::istream& operator>>(std::istream& is, Line& l);
std::ostream& operator<<(std::ostream& os, Line& l);
#endif // EXPAND
#endif // LINE_H
