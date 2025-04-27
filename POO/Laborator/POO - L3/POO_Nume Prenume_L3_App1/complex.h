#ifndef COMPLEX_H
#define COMPLEX_H
class Complex {
private:
    int a;
    int b;
public:
    //Constructori
    Complex();
    Complex(int, int);
    Complex(const Complex&);

    //Destructori
    ~Complex();

    //Metode
    void afiseaza() const;
    void setA(int);
    void setB(int);
    int getA() const;
    int getB() const;

    void adunare(const Complex&) const;
    void modul() const;
    static double modul(const Complex&);
};
#endif