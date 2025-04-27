#include <iostream>

#include "complex.h"
#include "puncte.h"

using namespace std;

int main() {
    Complex z1(3, 4);
    Complex z2(1, 2);

    std::cout << "Numărul complex z1 este: ";
    z1.afiseaza();

    std::cout << "Numărul complex z2 este: ";
    z2.afiseaza();

    z1.adunare(z2);

    z1.modul();

    cout << "Modulul lui z2 este: " << Complex::modul(z2) << '\n';
    
    Punct p1(3, 4);
    Punct p2(6, 8);

    cout << "Primul punct: ";
    p1.afiseaza();

    cout << "Al doilea punct: ";
    p2.afiseaza();

    cout << "Distanta dintre punctele p1 si p2: " << p1.dist(p2) << '\n';

    cout << "*Distanta dintre punctele p1 si p2: " << Punct::dist(p1, p2) << '\n';

    cout << "Punctul p1 se afla pe dreapta x - 3 = 0? " << (p1.peDreapta(1, -3) ? "Da" : "Nu") << '\n';

    return 0;
}
