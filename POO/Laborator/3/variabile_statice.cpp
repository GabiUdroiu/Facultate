#include <iostream>

using namespace std;

class MyClass {
public:
    static int count; // Variabila statica de membru
    MyClass() {
        count++; // Incrementam variabila statica in constructor
    }
};

int MyClass::count = 0; // Initializare a variabilei statice de membru

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;
    
    cout << "Numarul de obiecte create: " << MyClass::count << endl; // Afiseaza 3

    return 0;
}