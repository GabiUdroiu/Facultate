#include <iostream>
#include <fstream>
#define INF 1000000  // Large number to simulate infinity
using namespace std;

ifstream f("date.in");
int a[20][100], d[100][100], c[100][100], n, m;

void creareMatrice(int n, int m, int a[20][100], int c[100][100])
{
    int x, y, cost;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
            if (i == j)
                c[i][j] = 0;
            else
                c[i][j] = INF;
        }

    for (int i = 1; i <= m; i++)
    {
        cout << "Dati extremitatile muchiei " << i  << endl;
        f >> x >> y >> cost;
        a[x][y]++;
        c[x][y] = cost;
    }
}

void afisareMatrice(int n, int mat[100][100])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mat[i][j] == INF)
                cout << "INF ";
            else
                cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void ROY_WARSHALL()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = a[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = (d[i][j] || (d[i][k] && d[k][j]));
}

void ROY_FLOYD()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (c[i][k] + c[k][j] < c[i][j])
                    c[i][j] = c[i][k] + c[k][j];
}

int main()
{
    cout << "nr de noduri: ";
    f >> n;
    cout << "nr de muchii: ";
    f >> m;

    creareMatrice(n, m, a, c);

    cout << "\nMatricea de adiacenta (Roy-Warshall):" << endl;
    afisareMatrice(n, a);

    ROY_WARSHALL();

    cout << "\nMatricea drumurilor (Roy-Warshall):" << endl;
    afisareMatrice(n, d);

    ROY_FLOYD();

    cout << "\nMatricea costurilor minime (Roy-Floyd):" << endl;
    afisareMatrice(n, c);

    return 0;
}