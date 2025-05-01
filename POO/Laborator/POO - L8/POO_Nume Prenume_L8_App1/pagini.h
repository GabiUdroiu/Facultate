#ifndef PAGINI_H
#define PAGINI_H

#include <iostream>

using namespace std;



class Pagina { 
private: 
    const char* content; //dc e const....
    int pg;  //numarul paginii 
     
public: 
    Pagina(); 
    Pagina(const char* content, int pg); 
     
    friend istream& operator>>(istream&, Pagina&); 
    friend ostream& operator<<(ostream&, const Pagina&); 
     
    const char* continut() const; 
    int getPg() const; 
};

#endif