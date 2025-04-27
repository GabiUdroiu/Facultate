#include <iostream>

using namespace std;

class Matrice {
private:
    int m, n;
    int** data;
public:
    Matrice(int m, int n) : m(m), n(n), data(nullptr) {
        data = new int*[m]; 
        for (int i = 0; i < m; i++)
            data[i] = new int[n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> data[i][j];
    }

    ~Matrice() { 
        for (int i = 0; i < m; i++)
            delete[] data[i]; 
        delete[] data; 
    } 

    void afisare() const {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                cout << data[i][j] << ' ';
            cout << '\n';
        }
    }

    void adunare(const Matrice& other) {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) 
                data[i][j]+=other.data[i][j];
    }
};

int main() {
    int m, n;
    cout << "Introduceti numarul de linii si coloane: ";
    cin >> m >> n;

    cout << "Introduceti elementele primei matrice:\n";
    Matrice A(m, n);

    cout << "Introduceti elementele celei de-a doua matrice:\n";
    Matrice B(m, n);

    A.adunare(B);

    cout << "Rezultatul adunarii matricelor este:\n";
    A.afisare();

    return 0;
}
