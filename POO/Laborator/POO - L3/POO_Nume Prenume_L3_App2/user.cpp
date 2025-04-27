#include <iostream>

#include "user.h"

#define CURRENT_YEAR() 2025

using namespace std;

int User::strlen(char *s) {
    int n = 0;
    while(*s != '\0') {
        n++;
        s++;
    }
    return n;
}

bool User::strcif(char *s) {
    char chr[11] = "0123456789";
    while(*s != '\0') {
        for(int i = 0; i < 10; i++)
            if(*s == chr[i])
                return true;
        s++;
    }
    return false;
}

void User::strcpy(char* dest, char* sursa) {
    while((*dest++ = *sursa++) != '\0');
}

User::User() : nume(nullptr), parola(nullptr), an_nastere(0) {}

User::User(char* nume, char* parola, int an) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

    this->parola = new char[strlen(parola) + 1];
    strcpy(this->parola, parola);

    this->an_nastere = an;
}

User::~User() {
    delete[] nume;
    delete[] parola;
}

void User::afiseaza() const {
    cout << "Nume: " << nume 
         << "\nParola: " << parola
         << "\nAn nastere: " << an_nastere << '\n';
}

bool User::verifica_parola() const {
    return (strlen(parola) >= 8 && strcif(parola));
}

void User::setAn(int an) {
    an_nastere = an;
}

int User::getAn() const {
    return an_nastere;
}

int User::varsta() const {
    return CURRENT_YEAR() - an_nastere;
}

