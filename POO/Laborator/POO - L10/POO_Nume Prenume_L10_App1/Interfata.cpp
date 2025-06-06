#include <iostream>
#include <cstring>

using namespace std;

class Element {
protected:
    int x, y;
    int w, h;
public:
    Element();
    Element(int, int, int, int);
    Element(const Element&);
    virtual ~Element();

    virtual void afis();
    virtual double arie();
    virtual Element* Clona();
};

// Constructori și destructor
Element::Element() : x(0), y(0), w(0), h(0) {}

Element::Element(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}

Element::Element(const Element& e) {
    x = e.x;
    y = e.y;
    w = e.w;
    h = e.h;
}

Element::~Element() {}

void Element::afis() {
    cout << "Element generic la (" << x << ", " << y << "), dimensiune: " << w << "x" << h << "\n";
}

double Element::arie() {
    return w * h;
}

Element* Element::Clona() {
    return new Element(*this);
}

// -------------------------------

class Buton : public Element {
private:
    char* text;
public:
    Buton();
    Buton(int, int, int, int, const char*);
    Buton(const Buton&);
    ~Buton();

    void afis() override;
    double arie() override;
    char* getText();
    Element* Clona() override;
};

Buton::Buton() : Element() {
    text = nullptr;
}

Buton::Buton(int x, int y, int w, int h, const char* t) : Element(x, y, w, h) {
    text = new char[strlen(t) + 1];
    strcpy(text, t);
}

Buton::Buton(const Buton& b) : Element(b) {
    text = new char[strlen(b.text) + 1];
    strcpy(text, b.text);
}

Buton::~Buton() {
    delete[] text;
}

void Buton::afis() {
    cout << "Buton \"" << text << "\" la (" << x << ", " << y << "), dimensiune: " << w << "x" << h << "\n";
}

double Buton::arie() {
    return w * h;
}

char* Buton::getText() {
    return text;
}

Element* Buton::Clona() {
    return new Buton(*this);
}

// -------------------------------

class Caseta : public Element {
private:
    int lungime;
public:
    Caseta();
    Caseta(int, int, int, int, int);
    Caseta(const Caseta&);
    ~Caseta();

    void afis() override;
    double arie() override;
    int getLungime();
    Element* Clona() override;
};

Caseta::Caseta() : Element(), lungime(0) {}

Caseta::Caseta(int x, int y, int w, int h, int l) : Element(x, y, w, h), lungime(l) {}

Caseta::Caseta(const Caseta& c) : Element(c), lungime(c.lungime) {}

Caseta::~Caseta() {}

void Caseta::afis() {
    cout << "Caseta text (lungime: " << lungime << ") la (" << x << ", " << y << "), dimensiune: " << w << "x" << h << "\n";
}

double Caseta::arie() {
    return w * h;
}

int Caseta::getLungime() {
    return lungime;
}

Element* Caseta::Clona() {
    return new Caseta(*this);
}

// -------------------------------

class Fereastra {
private:
    int count;
    Element* elemente[100];
public:
    Fereastra();
    Fereastra(const Fereastra&);
    ~Fereastra();

    Fereastra& addElement(Element*);
    Element* getElement();
    void elements();
    void infoElemente();
};

Fereastra::Fereastra() {
    count = 0;
}

Fereastra::Fereastra(const Fereastra& f) {
    count = f.count;
    for (int i = 0; i < count; ++i) {
        elemente[i] = f.elemente[i]->Clona();
    }
}

Fereastra::~Fereastra() {
    for (int i = 0; i < count; ++i) {
        delete elemente[i];
    }
}

Fereastra& Fereastra::addElement(Element* e) {
    if (count < 100) {
        elemente[count++] = e;
    }
    return *this;
}

Element* Fereastra::getElement() {
    if (count == 0)
        return nullptr;
    return elemente[count - 1];
}

void Fereastra::elements() {
    cout << "Elemente in fereastra:\n";
    for (int i = 0; i < count; ++i) {
        elemente[i]->afis();
    }
}

void Fereastra::infoElemente() {
    cout << "Informatii despre elemente:\n";
    for (int i = 0; i < count; ++i) {
        cout << "- Aria elementului " << i + 1 << ": " << elemente[i]->arie() << "\n";
    }
}

// -------------------------------

int main() {
    Element* e1 = new Buton(10, 20, 100, 30, "OK");
    Element* e2 = new Caseta(50, 60, 200, 40, 10);

    Fereastra f;
    f.addElement(e1).addElement(e2);

    f.elements();
    cout << "--------------------\n";
    f.infoElemente();

    return 0;
}
