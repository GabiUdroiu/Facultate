#include <iostream>

#include "user.h"

using namespace std;

int main() {
    char nume[] = "Gabi Usturoiu";
    char parola[] = "azorel123";
    int an_nastere = 2005;

    User user1(nume, parola, an_nastere);

    user1.afiseaza();

    if (user1.verifica_parola()) {
        cout << "Parola valida" << '\n';
    } else {
        cout << "Parola invalida" << '\n';
    }

    cout << "Varsta: " << user1.varsta() << " ani" << '\n';

    user1.setAn(2000);
    cout << "Anul actualizat: " << user1.getAn() << '\n';

    return 0;
}
