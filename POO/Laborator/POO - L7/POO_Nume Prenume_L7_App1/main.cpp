#include <iostream>

#include "multime.h"

using namespace std;


void Multime::init(int m, int* data)
{
    this->m = m;
    this->data = new int[m];
    for(int i = 0; i < m; i++)
        this->data[i] = data[i];
}

Multime::Multime() : m(0), data(nullptr) {}
Multime::Multime(int m, int* data) {init(m, data);}
Multime::Multime(const Multime& other) {init(other.m, other.data);}
Multime::~Multime() {delete[] data;}

ostream& operator<<(ostream& out, const Multime& a)
{
    for(int i = 0; i < a.m; ++i)
        out << a.data[i] << ' ';
    out << '\n';

    return out;
}

istream& operator>>(istream& in, Multime& a)
{
    cout << "Nr de elem: ";
    in >> a.m;
    a.data = new int[a.m];
    cout << "Elem: ";
    for(int i = 0; i < a.m; ++i)
        in >> a.data[i];

    return in;
}

Multime& Multime::operator=(const Multime& other)
{
    if(this != &other)
    {
        delete[] data;
        init(other.m, other.data);
    }

    return *this;
}

Multime Multime::operator+(const Multime& other)
{
    //reuniune
    Multime temp;
    temp.m = this->m + other.m;
    temp.data = new int[temp.m];
    int n = 0;

    for(int i = 0; i < m; ++i)
        temp.data[n++] = data[i];

    for(int i = 0; i < other.m; ++i)
    {
        bool gasit = false;
        for(int j = 0; j < m; ++j)
            if(other.data[i] == data[j]) 
            {
                gasit = true;
                break;
            }

        if(!gasit) temp.data[n++] = other.data[i];
    }

    temp.m = n;

    return temp;
}

Multime Multime::operator*(const Multime& other)
{
    //intersectie
    Multime temp;
    temp.m = this->m + other.m;
    temp.data = new int[temp.m];
    int n = 0;

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < other.m; ++j)
            if(data[i] == other.data[j]) 
            {
                temp.data[n++] = data[i];
                break;
            }
    }

    temp.m = n;

    return temp;
}

Multime Multime::operator-(const Multime& other)
{
    //diferenta
    Multime temp;
    temp.m = m;
    temp.data = new int[m];
    int n = 0;

    for(int i = 0; i < m; ++i)
    {
        bool gasit = false;
        for(int j = 0; j < other.m; ++j)
            if(data[i] == other.data[j]) 
            {
                gasit = true;
                break;
            }
        
        if(!gasit)
            temp.data[n++] = data[i];
    }

    temp.m = n;

    return temp;
}

int main() 
{
    Multime a, b;
    
    cin >> a >> b;

    cout << "A: " << a;
    cout << "B: " << b;

    Multime c = a + b;
    cout << "A + B: " << c;

    Multime d = a * b;
    cout << "A * B: " << d;

    Multime e = a - b;
    cout << "A - B: " << e;

    return 0;
}