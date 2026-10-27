#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdexcept>

class EmptyTriangleEx {};

class CustomTriangleEx {
public:
    double a, b, c;
    CustomTriangleEx(double x, double y, double z) : a(x), b(y), c(z) {}
};

class DerivedTriangleEx : public std::invalid_argument {
public:
    double a, b, c;
    DerivedTriangleEx(double x, double y, double z)
        : std::invalid_argument("Некоректні сторони трикутника"), a(x), b(y), c(z) {}
};

double calcNoSpec(double a, double b, double c);             
double calcThrowEmpty(double a, double b, double c) noexcept;
double calcStandard(double a, double b, double c);           
double calcCustom(double a, double b, double c, int type);   

#endif