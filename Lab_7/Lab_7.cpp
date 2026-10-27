#include <iostream>
#include <windows.h>
#include "TriangleException.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, b, c;
    cout << "Введіть сторони трикутника:\n";
    cout << "Сторона 1: "; cin >> a;
    cout << "Сторона 2: "; cin >> b;
    cout << "Сторона 3: "; cin >> c;
    cout << "----------------------------------------\n";

    try {
        double area = calcNoSpec(a, b, c);
        cout << "[Успіх] Площа трикутника: " << area << "\n\n";
    }
    catch (...) {
        cout << "[Увага] Введені сторони є помилковими.\n\n";
    }

    try {
        calcNoSpec(a, b, c);
    }
    catch (const char* msg) {
        cout << "1." << msg << endl;
    }

    try {
        calcStandard(a, b, c);
    }
    catch (const invalid_argument& e) {
        cout << "2." << e.what() << endl;
    }

    try {
        calcCustom(a, b, c, 1);
    }
    catch (const EmptyTriangleEx&) {
        cout << "3.EmptyTriangleEx (пустий клас)." << endl;
    }

    try {
        calcCustom(a, b, c, 2);
    }
    catch (const CustomTriangleEx& e) {
        cout << "4.CustomTriangleEx з полями -> a = " << e.a << ", b = " << e.b << ", c = " << e.c << endl;
    }

    try {
        calcCustom(a, b, c, 3);
    }
    catch (const DerivedTriangleEx& e) {
        cout << "5." << e.what() << " [Сторони: " << e.a << ", " << e.b << ", " << e.c << "]" << endl;
    }

    return 0;
}