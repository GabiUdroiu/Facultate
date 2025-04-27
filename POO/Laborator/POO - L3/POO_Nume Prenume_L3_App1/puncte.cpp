#include <iostream>
#include <cmath>

#include "puncte.h"

using namespace std;

Punct::Punct() : p(0,0) {}

Punct::Punct(int x, int y) : p(x,y) {}

Punct::Punct(const Punct& other) : p(other.p) {}

Punct::~Punct() {}

void Punct::afiseaza() const {
    std::cout << "Punctul are coordonatele: (" << p.x << ", " << p.y << ")" << std::endl;
}

int Punct::getX() const {
    return p.x;
}

int Punct::getY() const {
    return p.y;
}

void Punct::setXY(int x, int y) {
    p.x = x;
    p.y = y;
}

punct Punct::getXY() const {
    return p;
}

double Punct::dist(const Punct& other) const {
    return sqrt(pow(p.x - other.p.x, 2) + pow(p.y - other.p.y, 2));
}

double Punct::dist(const Punct& p1, const Punct& p2) {
    //return sqrt(pow(p1.p.x - p2.p.x, 2) + pow(p1.p.y - p2.p.y, 2));
    //fancy :3
    return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}

bool Punct::peDreapta(int a, int b) {
    return (a * p.x + b == 0);
}

