/*
Creati o clasa care se numeste Contbancar cu 4 membrri
-suma
-adauga (modificare suma, afisare mesaj de adaugare)
-retrage (modificare suma, afisare mesaj de retragere)
-sold (afisare suma)
*/
#include <iostream>

#define CLEAR_SCREEN() printf("\x1b[H\x1b[2J\x1b[3J")
///clear screen pt ca nu mi place sa se umple consola de meniu
/// nu fol system(cls) pt ca nu merge in terminalu din vs

class ContBancar{
private:
    float suma = 0;

public:
    void adauga(){ 
        int numar;
        std::cin >> numar;
        if(numar > 0) {
            suma += numar;
            std::cout << "\nIn contul dvs. s-a adaugat suma de " << numar;
        }
        else std::cout << "\nSuma introdusa este invalida";
    }
    
    void retragere(){
        int numar;
        std::cin >> numar;
        if(numar <= suma) {
            suma -= numar;
            std::cout << "\nIn contul dvs. s-a retras suma de " << numar;
        }
        else std::cout << "\nSuma introdusa este invalida/sau n ai bani";
    }
    
    void sold(){
        std::cout << suma;
    }
};

int main() {
    ContBancar id7383;
    int choice;
    ///id7383.suma = 0; //daca nu e privat
    do {
        //Meniu
        std::cout 
        << "\n\n--Meniu--"
        << "\n1.Adauga"
        << "\n2.Retragere"
        << "\n3.Sold"
        << "\n4.Inchide"
        << "\n---------\n";

        std::cin >> choice;
        CLEAR_SCREEN();
        switch(choice) {
            case 1: { 
                std::cout << "\nAdauga: ";
                id7383.adauga();
                break;
            }
            case 2: {
                std::cout << "\nRetrage: ";
                id7383.retragere();
                break;
            }
            case 3: {
                std::cout << "\nSold curent: ";
                id7383.sold();
                break;
            } 
            case 4: {
                std::cout << "\nAplicatia s-a inchis";
                return 0;
                break;
            }
            default: std::cout << "\nInstructiune necunoscuta, introduceti iar ";
        }
    } while(choice != 4);

    return 0;
}