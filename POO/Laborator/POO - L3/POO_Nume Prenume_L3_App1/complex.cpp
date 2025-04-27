#include <iostream>
#include <cmath>

#include "Complex.h"

using namespace std;

Complex::Complex() : a(0), b(0) {}

Complex::Complex(int a, int b) : a(a), b(b) {}

Complex::Complex(const Complex& other) : a(other.a), b(other.b) {}

Complex::~Complex() {}

void Complex::afiseaza() const {
    cout << a << " + " << b << "i" << '\n';
}

void Complex::setA(int a) {
    this->a = a;
}

void Complex::setB(int b) {
    this->b = b;
}

int Complex::getA() const {
    return a;
}

int Complex::getB() const {
    return b;
}

void Complex::adunare(const Complex& other) const {
    int resultA = a + other.a;
    int resultB = b + other.b;
    cout << "Suma celor doua numere complexe este: " << resultA << " + " << resultB << "i" << '\n';
}

void Complex::modul() const {
    double r = sqrt(a * a + b * b);
    cout << "Modulul numarului complex este: " << r << '\n';
}

double Complex::modul(const Complex& z) {
    return double(z.a * z.a + z.b * z.b);
}