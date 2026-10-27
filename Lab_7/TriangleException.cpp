#include "TriangleException.h"
#include <cmath>

bool checkSides(double a, double b, double c) {
    return (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a));
}

double calcNoSpec(double a, double b, double c) {
    if (checkSides(a, b, c)) {
        throw "Помилка (без специфікації): неможливий трикутник!";
    }
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double calcThrowEmpty(double a, double b, double c) noexcept {
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double calcStandard(double a, double b, double c) {
    if (checkSides(a, b, c)) {
        throw std::invalid_argument("Стандартне виключення: порушено нерівність трикутника.");
    }
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double calcCustom(double a, double b, double c, int exceptionVariant) {
    if (checkSides(a, b, c)) {
        if (exceptionVariant == 1) {
            throw EmptyTriangleEx();
        }
        else if (exceptionVariant == 2) {
            throw CustomTriangleEx(a, b, c);
        }
        else if (exceptionVariant == 3) {
            throw DerivedTriangleEx(a, b, c);
        }
    }
    double p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}