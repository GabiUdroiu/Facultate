#ifndef CARTI_H
#define CARTI_H

#include <iostream>

#include "pagini.h"

using namespace std;

class Carte { 
    protected: 
        Pagina* pagini; 
        int npg;  // numar de pagini 
        const char* author; 
     
    public: 
        Carte(); 
        Carte(const char* author, int size); 
        Carte(const Carte&); 
        ~Carte(); 
     
        friend istream& operator>>(istream&, Carte&); 
        friend ostream& operator<<(ostream&, const Carte&); 
        Carte& operator=(const Carte&); 
     
        int getNpg() const; 
        void print() const; 

            ///
        static int strlen(const char*);
        static void strcpy(char*, const char*);
};

class CarteFictiune : public Carte { 
private: 
    const char* gen; 
public: 
    CarteFictiune(const char* author, const char* gen, int siez); 
     
    void print() const; 
};

class CarteNonFictiune : public Carte { 
private: 
    const char* subiect; 
     
public: 
    CarteNonFictiune(const char* author, const char* subiect, int size); 
     
    void print() const; 
}; 

#endif