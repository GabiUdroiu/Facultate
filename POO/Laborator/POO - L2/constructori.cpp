// 06.03.2025 -- Laborator OOP - 2

#include <iostream>

using namespace std;

class MyClass
{
public:
    int value;
    // constructor implicit
    MyClass()
    {
        value = 0;
        cout << "Constructor implicviti apaelat!" << endl;
    }

    // constructor cu parametrii
    MyClass(int x)
    {
        value = x;
        cout << "Construcotr cu parametri apelatai" << endl;
    }

    // constructor de copiere
    MyClass(const MyClass &other)
    {
        value = other.value;
        cout << "Construcutor de copiere" << endl;
    }

    // constructor de mutare
    MyClass(MyClass &&other) noexcept
    {
        value = other.value;
        other.value = 0;
        cout << "Constructor de mutare" << endl;
    }

    ~MyClass()
    {
        cout << "Destructor apelat" << endl;
    }
};

class MyClass1
{
public:
    int *value;

    MyClass1(int x)
    {
        value = new int(x);
    }

    MyClass1(MyClass &&other)
    {
        value = &other.value;
        other.value = NULL;
    }

    ~MyClass1()
    {
        delete value;
    }
};

class Dreptunghi
{
public:
    int w, h;
    // Dreptunghi(int x,int y){
    //     w = x;
    //     h = y;
    // }

    Dreptunghi(int x, int y) : w(x), h(y) {}

    int aria() { return w * h; }
};

int main()
{
    MyClass ob1;
    MyClass ob2(10);
    MyClass ob3 = ob2;
    MyClass ob4 = move(ob3);

    cout << ob1.value << endl;
    cout << ob2.value << endl;
    cout << ob3.value << endl;
    cout << ob4.value << endl;

    MyClass1 ob5(100);
    MyClass1 ob6 = move(ob5);

    cout << *ob5.value << ' ' << *ob6.value << endl;

    return 0;
}