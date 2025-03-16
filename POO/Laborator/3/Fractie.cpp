// 13.03.2025 -- Laborator OOP - 3

/*
    Implementati clasa fractie
    - doua atribute:numarator,numitor int
    - un atrib static: unu (fractie)
    - un constructor implicit si unul cu param
    - destructor
    - getters,setters
*/

#include <iostream>

using namespace std;

class Fractie {
private:
    int numarator, numitor;
    int cmmdc(int a,int b);
    static int euclid(int numarator, int numitor){
        while(numarator != numitor){
            if(numarator > numitor)
                numarator -= numitor;
            else
                numitor -= numarator;
        }
        return numarator;
    }
    
public:
    Fractie() : numarator(0), numitor(1) {}
    Fractie(int a, int b) {
        this->numarator = a;
        this->numitor = b;
    }
    //Setters
    void setNumarator(int value);
    void setNumitor(int value);

    //Getters
    int getNumarator();
    int getNumitor();
    double valoare();

    //Functionality
    Fractie simplifica(); //era void
    Fractie adunare(Fractie& f);
    Fractie scadere(Fractie& f);
    Fractie produs(Fractie& f);
    Fractie cat(Fractie& f);
    static double procent(Fractie& f);
    static Fractie add(Fractie& f1, Fractie& f2);
    void afis();

};

//Afisare
void Fractie::afis() {
    cout << this->numarator;
    if(this->numitor > 1) cout << "/" << this->numitor; //daca e 5/1, afisam doar 5, fara " /1 ".
    cout << '\n';
}

//Setters
void Fractie::setNumarator(int value){
    this->numarator = value;
}

void Fractie::setNumitor(int value){
    this->numitor = value;
}

//Getters
int Fractie::getNumarator() {
    return this->numarator;
}

int Fractie::getNumitor() {
    return this->numitor;
}

//Functionality
double Fractie::valoare() {
    return (double)(this->numarator)/(this->numitor);
}

int Fractie::cmmdc(int numarator, int numitor) {
    return euclid(numarator,numitor);
}

Fractie Fractie::simplifica() {
    int val = Fractie::cmmdc(this->numarator,this->numitor);
    if(val == 1) //ireductibil
        return *this;
    else{
        this->numarator/=val;
        this->numitor/=val;
    }
    return *this;
}

Fractie Fractie::adunare(Fractie& f) {
    this->numarator = this->numarator*f.numitor+f.numarator*this->numitor;
    this->numitor = this->numitor*f.numitor;
    //n,m= ^
    //Fractie rezultat(n,m);
    //return rezultat.simplifica();
    return (*this).simplifica();
}

Fractie Fractie::scadere(Fractie& f) {
    this->numarator = this->numarator*f.numitor-f.numarator*this->numitor;
    this->numitor = this->numitor*f.numitor;
    //n,m= ^
    //Fractie rezultat(n,m);
    //return rezultat.simplifica();
    return (*this).simplifica();
}

Fractie Fractie::produs(Fractie& f) {
    this->numarator = this->numarator*f.numarator;
    this->numitor = this->numitor*f.numitor;
    //n,m= ^
    //Fractie rezultat(n,m);
    //return rezultat.simplifica();
    return (*this).simplifica();
}

Fractie Fractie::cat(Fractie& f) {
    this->numarator = this->numarator*f.numitor;
    this->numitor = this->numitor*f.numarator;
    //n,m= ^
    //Fractie rezultat(n,m);
    //return rezultat.simplifica();
    return (*this).simplifica();
}

Fractie Fractie::add(Fractie& f1, Fractie& f2) {
    int n = f1.numarator * f2.numitor + f2.numarator * f1.numitor;
    int m = f1.numitor * f2.numitor;
    Fractie f(n, m);
    f.simplifica();
    return f;
}

double Fractie::procent(Fractie& f) {
    return f.valoare()*100;
}

int main() {
    Fractie f(3,4);
    Fractie g(3,2);
    f.adunare(g).afis();

    Fractie f1(12,4), f2(8,4);
    Fractie::add(f1,f2).afis();

    Fractie b(2,3);
    cout << Fractie::procent(b) << '%';

    return 0;
}