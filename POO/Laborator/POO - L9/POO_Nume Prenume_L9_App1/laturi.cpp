#include <iostream>
using namespace std;

class Latura {
private:
    int lungime;
public:
    Latura() : lungime(0) {}
    Latura(int l) : lungime(l) {}

    int getL() const {
        return lungime;
    }

    Latura& operator=(const Latura& l) {
        if (this != &l)
            lungime = l.lungime;
        return *this;
    }

    friend istream& operator>>(istream& in, Latura& l) {
        cout << "Introduceti lungimea laturii: ";
        in >> l.lungime;
        return in;
    }
};

class Figura {
protected:
    Latura* lat;
    int nrLat;
public:
    Figura() : lat(nullptr), nrLat(0) {}
    
    Figura(int nr) : nrLat(nr) {
        lat = new Latura[nrLat];
        for (int i = 0; i < nrLat; ++i)
            cin >> lat[i];
    }

    Figura(Latura* l, int nr) : nrLat(nr) {
        lat = new Latura[nrLat];
        for (int i = 0; i < nrLat; ++i)
            lat[i] = l[i];
    }

    Figura(const Figura& f) : nrLat(f.nrLat) {
        lat = new Latura[nrLat];
        for (int i = 0; i < nrLat; ++i)
            lat[i] = f.lat[i];
    }

    virtual ~Figura() {
        delete[] lat;
    }

    Figura& operator=(const Figura& f) {
        if (this != &f) {
            delete[] lat;
            nrLat = f.nrLat;
            lat = new Latura[nrLat];
            for (int i = 0; i < nrLat; ++i)
                lat[i] = f.lat[i];
        }
        return *this;
    }

    virtual double arie() = 0;

    int perimetru() {
        int p = 0;
        for (int i = 0; i < nrLat; ++i)
            p += lat[i].getL();
        return p;
    }

    friend ostream& operator<<(ostream& out, const Figura& f) {
        out << "Figura cu " << f.nrLat << " laturi: ";
        for (int i = 0; i < f.nrLat; ++i)
            out << f.lat[i].getL() << " ";
        out << "\n";
        return out;
    }
};

class Triunghi : public Figura {
public:
    Triunghi() : Figura(2) {} //2 pt ca baza si inaltimea, 2laturi

    double arie() override {
        int b = lat[0].getL();
        int h = lat[1].getL();
        return (b * h) / 2.0;
    }
};

class Dreptunghi : public Figura {
public:
    Dreptunghi() : Figura(2) {}

    double arie() override {
        int l = lat[0].getL();
        int L = lat[1].getL();
        return l * L;
    }
};

int main() {
    Figura* fig1 = new Triunghi();
    cout << *fig1;
    cout << "Perimetru Triunghi (baza + inaltime): " << fig1->perimetru() << "\n";
    cout << "Arie Triunghi: " << fig1->arie() << "\n\n";

    Figura* fig2 = new Dreptunghi();
    cout << *fig2;
    cout << "Perimetru Dreptunghi (l + L): " << fig2->perimetru() << "\n";
    cout << "Arie Dreptunghi: " << fig2->arie() << "\n\n";

    delete fig1;
    delete fig2;

    return 0;
}
