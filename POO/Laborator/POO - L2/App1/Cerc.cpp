/* 
Implementati clasa cerc
- Un atribut raza(double)
- Trei metode: circum(2 × radius × π), getRaza, setRaza 
- Trei constructori: implicit cu parametri si de copiere si un destructor
*/

#include <iostream>

const double PI = 3.14;

class Cerc {
private:
    double r;

public:
    Cerc(){}

    Cerc(double x) {
        r = x;
    }

    Cerc(const Cerc& other) {
        r = other.r;
    }

    void setRaza(double x) {
        std::cout << "Valoare pentru raza: ";
        r = x;
    }
        
    double getRaza() {
        return r;
    }
        
    double circum() {
        return 2*r*PI;
    }
        
    ~Cerc(){}
};