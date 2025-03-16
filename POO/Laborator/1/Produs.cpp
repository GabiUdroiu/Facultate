/* 
Scrieti o clasa Produs, care are 3 membri:
- pret 
- stoc
- valoare
*/
#include <iostream>

class Produs {
public:
    float pret;
    int stoc;

    float valoare() {
        return pret*stoc;
    } 
};

int main() {
    Produs produs;
    float p;
    int q;

    std::cout << "Introduceti pretul si cantitatea:\n";
    std::cin >> p >> q;
    
    produs.pret = p;
    produs.stoc = q;
    
    std::cout << "Valoarea toatala a stocului este: " << produs.valoare();
    
    return 0;
}