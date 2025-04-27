#include <iostream>

using namespace std;

int a[20][100], y, x, VIZ[100], TATA[100], n, m, URM[100], S[100];

void creareMatrice(int n, int m, int a[20][100])
{
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cout << "Dati extremitatile muchiei " << i << ": ";
        cin >> x >> y;
        a[x][y]++;
        ///NEORIENTAT
        if (x != y)
          a[y][x]++;
    }
}

void Viziteaza (int x) {
    cout << x << " ";
}

void BF (int x)
{
    Viziteaza(x);
    VIZ[x] = 1;
    TATA[x] = 0;
    int coada = 1, varf = 1;
    S[coada] = x;
    while (varf <= coada)
    {
        int i = S[varf];
        int j = URM[i] + 1;
        while (a[i][j] == 0 && j <= n)
            j++;
        if (j > n)
            varf++;
        else
        {
            URM[i] = j;
            if (VIZ[j] == 0)
            {
                Viziteaza(j);
                VIZ[j] = 1;
                TATA[j] = i;
                coada++;
                S[coada] = j;
            }
        }

    }
}

int main()
{
    cout << "Nr. noduri: ";
    cin >> n;
    cout << "Nr. muchii: ";
    cin >> m;
    creareMatrice(n, m, a);

    cout << "Introduceti nodul de pornire: ";
    cin >> x;

    BF(x);
}
