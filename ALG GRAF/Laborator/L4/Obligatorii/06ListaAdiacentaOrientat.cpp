#include <iostream>

using namespace std;

int n, m, a[20][100];

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

void afisareMatrice(int n, int a[20][100])
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void listaAdiac(int n, int a[20][100])
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (j = 1; j <= n; j++)
            if (a[i][j] != 0)
                cout << j;
        cout << endl;
    }
}

int main()
{
    cout << "Nr. noduri: ";
    cin >> n;
    cout << "Nr. muchii: ";
    cin >> m;

    creareMatrice(n, m, a);
    listaAdiac(n, a);
}
