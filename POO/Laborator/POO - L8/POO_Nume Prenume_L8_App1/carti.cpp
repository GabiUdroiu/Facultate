#include <iostream>

#include "carti.h"
#include "pagini.h"

using namespace std;

int Carte::strlen(const char *s) {
    int n = 0;
    while(*s != '\0') {
        n++;
        s++;
    }
    return n;
}

void Carte::strcpy(char* dest, const char* sursa) {
    while((*dest++ = *sursa++) != '\0');
}

Carte::Carte() : pagini(nullptr), npg(0), author(nullptr) {}

Carte::Carte(const char* author, int npg) : npg(npg)
{
    pagini = new Pagina[npg];
    this->author = new char[Carte::strlen(author) + 1];
    Carte::strcpy((char*) this->author, author);
}

Carte::Carte(const Carte& other) : npg(other.npg)
{
    pagini = new Pagina[npg];
    author = new char[Carte::strlen(other.author) + 1];
    Carte::strcpy((char*) author, other.author);
    
    for(int i = 0; i < npg; ++i)
        pagini[i] = other.pagini[i];
}

Carte::~Carte() {
    delete[] author; 
    delete[] pagini;
}

istream& operator>>(istream& in, Carte& c)
{
    char buffer[1000];

    cout << "Autor: ";
    in.getline(buffer,1000);
    c.author = new char[Carte::strlen(buffer) + 1];
    Carte::strcpy((char*) c.author, buffer);

    cout << "Nr pagini: ";
    in >> c.npg;
    in.get();//sau ignore

    c.pagini = new Pagina[c.npg];

    for(int  i = 0; i < c.npg; ++i)
        in >> c.pagini[i];

    return in;
}

ostream& operator<<(ostream& out, const Carte& c) 
{
    out << "Autor: " << c.author 
    << "\nNr. pagini: " << c.npg << '\n';
    for(int i = 0; i < c.npg; ++i)
        out << c.pagini[i];

    return out;
}

Carte& Carte::operator=(const Carte& other)
{
    npg = other.npg;
    pagini = new Pagina[npg];
    author = new char[Carte::strlen(other.author) + 1];
    Carte::strcpy((char*) author, other.author);

    for(int i = 0; i < npg; ++i)
        pagini[i] = other.pagini[i];
    
    return *this;
}

int Carte::getNpg() const {
    return npg;
}

void Carte::print() const {
    cout << *this;
}

CarteFictiune::CarteFictiune(const char* author, const char* gen, int size)
: Carte(author, size)
{
    this->gen = new char[Carte::strlen(gen) + 1];
    Carte::strcpy((char*)this->gen, gen);

    for (int i = 0; i < size; ++i)
        cin >> pagini[i];
}

void CarteFictiune::print() const {
    Carte::print();
    cout << "Gen: " << gen << '\n';
}

CarteNonFictiune::CarteNonFictiune(const char* author, const char* subiect, int size)
: Carte(author, size)
{
    this->subiect = new char[Carte::strlen(subiect) + 1];
    Carte::strcpy((char*)this->subiect, subiect);

    for (int i = 0; i < size; ++i)
        cin >> pagini[i];
}

void CarteNonFictiune::print() const {
    Carte::print();
    cout << "Subiect: " << subiect << '\n';
}