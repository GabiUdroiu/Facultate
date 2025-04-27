#ifndef PUNCTE_H
#define PUNCTE_H

#include <iostream>

using namespace std;

struct punct {
    int x, y;
    punct(int x, int y) : x(x), y(y) {}
};

class Punct {
private:
    punct p;

public:
    //Constructori
    Punct();
    Punct(int, int);
    Punct(const Punct&);

    //Destructor
    ~Punct();

    //Metode
    void afiseaza() const;
    void setXY(int, int);
    //#include <utility>
    //std::pair<int, int> getXY() const;
    punct getXY() const;

    int getX() const;
    int getY() const;

    double dist(const Punct&) const;
    static double dist(const Punct&, const Punct&);

    bool peDreapta(int, int);
};
#endif