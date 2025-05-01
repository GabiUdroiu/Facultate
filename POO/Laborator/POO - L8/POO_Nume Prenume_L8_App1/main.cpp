#include <iostream>

#include "carti.h"
#include "pagini.h"

using namespace std;

int main() 
{
    cout << "Creare carte -  - -\n";
    Carte carte1;
    cin >> carte1;
    cout << "\nDetalii carte:\n";
    carte1.print();

    cout << "\nConstructor de copiere:\n";
    Carte carteCopy = carte1;
    carteCopy.print();

    cout << "\nOperator de atribuire:\n";
    Carte carteAssigned;
    carteAssigned = carte1;
    carteAssigned.print();

    cout << "\nCarte fictiune:\n";
    CarteFictiune fict("George Orwell", "Distopie", 2);
    cout << '\n';
    fict.print();

    cout << "\nCarte nonfictiune:\n";
    CarteNonFictiune nonfict("Yuval Noah Harari", "Istorie", 2);
    cout << '\n';
    nonfict.print();

    return 0;
}
