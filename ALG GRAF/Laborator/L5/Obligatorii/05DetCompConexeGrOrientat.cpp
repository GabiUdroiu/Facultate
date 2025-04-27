#include <iostream>

using namespace std;

int a[20][100], y, x, VIZ[100], TATA[100], n, m, nrc, i, CC[100];

void creareMatrice(int n, int m, int a[20][100])
{
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cout << "Dati extremitatile muchiei " << i << ": ";
        cin >> x >> y;
        a[x][y]++;
    }
}

void Viziteaza (int x) {
    cout << x << " ";
    CC[x] = nrc;
}

void DF_Recursiv (int x)
{
    Viziteaza(x);
    VIZ[x] = 1;
    for (y = 1; y <= n; y++)
    {
        if ((a[x][y] >= 1 || a[y][x] >= 1) && VIZ[y] == 0)
        {
            TATA[y] = x;
            DF_Recursiv(y);
        }
    }
}

void COMPONENTE_CONEXE()
{
    nrc = 0;
    for (i = 1; i <= n; i++)
        CC[i] = 0;
    for (i = 1; i <= n; i++)
    {
        if (CC[i] == 0)
        {
            nrc++;
            DF_Recursiv(i);
            cout << endl;
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

    COMPONENTE_CONEXE();
}
