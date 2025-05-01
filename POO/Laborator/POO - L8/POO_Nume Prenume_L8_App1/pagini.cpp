#include <iostream>

#include "pagini.h"
#include "carti.h"

using namespace std;

Pagina::Pagina() : content(nullptr), pg(0) {}

Pagina::Pagina(const char* content, int pg) : pg(pg)
{
    this->content = new char[Carte::strlen(content) + 1];
    Carte::strcpy((char*) this->content, content);
}

int Pagina::getPg() const {return pg;}
const char* Pagina::continut() const {return content;}

istream& operator>>(istream& in, Pagina& p)
{
    char buffer[1000];
    cout << "Numarul paginii: ";
    in >> p.pg;
    in.get();//sau ignore
    cout << "Continutul paginii: ";
    in.getline(buffer, 1000);
    p.content = new char[Carte::strlen(buffer) + 1];
    Carte::strcpy((char*) p.content, buffer);
    //nu inteleg dc contentu e const..
    return in;
}

ostream& operator<<(ostream& out, const Pagina& p) 
{
    out << "Pagina " << p.pg << ": " << p.content << '\n';
    return out;
}