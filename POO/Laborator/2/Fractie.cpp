/*
atribute num,numit
constuct implicit cu parametri
metod egetteri si setteri
*/

#include <iostream>

using namespace std;

class Fractie {
private:
    double numarator;
    double numitor;

public:
    //constructori
    Fractie() : numarator(0), numitor(0) {}

    Fractie(double x, double y) {
        numarator = x;
        numitor = y;
    }
    
    //setteri
    void setNumarator(int x) {
        numarator = x;
    }

    void setNumitor(int x) {
        numarator = x;
    }

    //getteri
    double getNumarator() {
        return numarator;
    }

    double getNumitor() {
        return numitor;
    }

    int cmmdc(int a, int b)
    {
        while (a != b)
            if (a > b)
                a -= b;
            else
                b -= a;
        return a;
    }

    bool ireductibila() {
        if (cmmdc(numarator, numitor) != 1)
            return true;
        return false;
    }

    ~Fractie() {}
};

int main() {
    Fractie ob1(10, 5);
    cout << ob1.getNumarator() << endl;
    cout << ob1.getNumitor() << endl;
    cout << boolalpha << ob1.ireductibila() << endl;
    
    return 0;
}