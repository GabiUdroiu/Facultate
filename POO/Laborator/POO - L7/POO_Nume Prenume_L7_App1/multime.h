#ifndef MULTIME_H
#define MULTIME_H

#include <iostream>

using namespace std;

class Multime 
{ 
private: 
    int m; 
    int* data; 
    void init(int, int*); 
 
public: 
    // constructori 
    Multime(); 
    Multime(int, int*); 
    Multime(const Multime&); 
 
    // afisare 
    friend ostream& operator<<(ostream&, const Multime&); 
 
    // citire 
    friend istream& operator>>(istream&, Multime&); 
 
    // atribuire 
    Multime& operator=(const Multime&); 
 
    // reuniune 
    Multime operator+(const Multime&); 
 
    // intersectie 
    Multime operator*(const Multime&); 
 
    // diferenta 
    Multime operator-(const Multime&); 
 
    // destructor 
    ~Multime(); 
 
}; 

#endif