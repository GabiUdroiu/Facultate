#include <iostream>
using namespace std;

int a[20][100], y, x, VIZ[100], TATA[100], n, m, nrc, CC[100], S[100], URM[100];
int CE[100], L[100], len;

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

void DF (int x)
{
    Viziteaza(x);
    VIZ[x] = 1;
    TATA[x] = 0;
    int varf = 1;
    S[varf] = x;
    while (varf > 0)
    {
        int i = S[varf];
        int j = URM[i] + 1;

        while (a[i][j] == 0 && j <= n)
            j++;
        if (j > n)
            varf--;
        else
        {
            URM[i] = j;

            if (VIZ[j] == 0)
            {
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
    }
    for (int i = 1; i <= n; i++) {
        if (CC[i] == 0) {
            nrc++;
            DF(i);
        }
    }

    cout << "\nNumar componente conexe: " << nrc << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Nodul " << i << " apartine componentei " << CC[i] << endl;
    }
}

bool estePar = true;

void calculGrade(int n, int a[20][100]) {
    for (int i = 1; i <= n; i++) {
        int s = 0;
        cout << "Gradul nodului " << i << ": ";
        for (int j = 1; j <= n; j++)
            s += a[i][j];
        cout << s << endl;
        if (s % 2 != 0) estePar = false;
    }
}

bool esteC() {
    for (int i = 1; i <= n; i++)
        if (CC[i] == 0)
            return false;
    return true;
}

void Ciclueulerian(int nod) {
    int varf = 1, p, v;
    S[varf] = nod;
    len = 0;

    while (varf) {
        p = S[varf];
        v = 1;
        while (v <= n && a[p][v] == 0)
            v++;
        if (v > n) {
            len++;
            L[len] = p;
            varf--;
        } else {
            varf++;
            S[varf] = v;
            a[p][v]--;
            a[v][p]--;
        }
    }

    cout << "\nCiclu eulerian:\n";
    for (int i = len; i >= 1; i--)
        cout << L[i] << " ";
    cout << endl;
}

int main() {
    cout << "Nr. noduri: ";
    cin >> n;
    cout << "Nr. muchii: ";
    cin >> m;
    creareMatrice(n, m, a);

    COMPONENTE_CONEXE();

    if (nrc == 1) {
        cout << "Graful este conex." << endl;
    } else {
        cout << "Graful nu este conex. Are " << nrc << " componente." << endl;
    }

    calculGrade(n, a);
    if ((n != 1 || a[1][1] != 0) && esteC() && estePar) {
        cout << "\nGraful este eulerian.";
        Ciclueulerian(1);
    } else {
        cout << "\nGraful nu este eulerian.";
    }

    return 0;
}
