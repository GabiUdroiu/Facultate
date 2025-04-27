#include <iostream>

using namespace std;

int a[20][100], y, x, VIZ[100], TATA[100], n, m;

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

void DF_Recursiv (int x)
{
    Viziteaza(x);
    VIZ[x] = 1;
    for (y = 1; y <= n; y++)
    {
        if (a[x][y] >= 1 && VIZ[y] == 0)
        {
            TATA[y] = x;
            DF_Recursiv(y);
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

    DF_Recursiv(x);
}
