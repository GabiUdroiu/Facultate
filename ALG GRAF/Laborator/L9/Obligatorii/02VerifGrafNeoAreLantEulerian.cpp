#include <iostream>
using namespace std;

int a[20][100], VIZ[100], TATA[100], n, m, nrc, CC[100], S[100], URM[100];

void creareMatrice(int n, int m, int a[20][100]) {
    int x, y;
    for (int i = 1; i <= m; i++) {
        cout << "Dati extremitatile muchiei " << i << ": ";
        cin >> x >> y;
        a[x][y]++;
        if (x != y) a[y][x]++;
    }
}

void Viziteaza(int x) {
    CC[x] = nrc;
}

void DF(int x) {
    Viziteaza(x);
    VIZ[x] = 1;
    int varf = 1;
    S[varf] = x;
    while (varf > 0) {
        int i = S[varf];
        int j = URM[i] + 1;
        while (j <= n && a[i][j] == 0)
            j++;
        if (j > n)
            varf--;
        else {
            URM[i] = j;
            if (VIZ[j] == 0) {
                Viziteaza(j);
                VIZ[j] = 1;
                TATA[j] = i;
                varf++;
                S[varf] = j;
            }
        }
    }
}

void COMPONENTE_CONEXE() {
    nrc = 0;
    for (int i = 1; i <= n; i++) {
        VIZ[i] = 0;
        CC[i] = 0;
        URM[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (CC[i] == 0) {
            nrc++;
            DF(i);
        }
    }
}

bool esteConex() {
    return nrc == 1;
}

bool areLantEulerianDeschis() {
    int countImpare = 0;
    for (int i = 1; i <= n; i++) {
        int grad = 0;
        for (int j = 1; j <= n; j++)
            grad += a[i][j];
        if (grad % 2 == 1)
            countImpare++;
    }
    return (countImpare == 2 && esteConex());
}

int main() {
    cout << "Nr. noduri: ";
    cin >> n;
    cout << "Nr. muchii: ";
    cin >> m;

    creareMatrice(n, m, a);
    COMPONENTE_CONEXE();

    if (esteConex())
        cout << "Graful este conex.\n";
    else
        cout << "Graful NU este conex. Componente: " << nrc << "\n";

    if (areLantEulerianDeschis())
        cout << "Graful are lant eulerian deschis.\n";
    else
        cout << "Graful NU are lant eulerian deschis.\n";

    return 0;
}
