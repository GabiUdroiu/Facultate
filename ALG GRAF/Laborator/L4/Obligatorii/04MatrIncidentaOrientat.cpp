#include <iostream>

using namespace std;

int n, m, b[20][100];

void creareMatriceIncid(int n, int m, int b[20][100])
{
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cout << "Dati extremitatile muchiei " << i << ": ";
        cin >> x >> y;
        b[x][i] = 1;
        b[y][i] = -1;
    }
}

void afisareMatrice(int n, int b[20][100])
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    cout << "Nr. noduri: ";
    cin >> n;
    cout << "Nr. muchii: ";
    cin >> m;

    creareMatriceIncid(n, m, b);
    afisareMatrice(n, b);
}
