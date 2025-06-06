#include <iostream>
#include <fstream>
#define INF 1000000
using namespace std;

ifstream f("date.in");
int a[20][100], d[100][100], c[100][100], n, m;
int t[100], S[100], TATA[100];

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

void Dijkstra(int s)
{
    for (int i = 1; i <= n; i++) {
        S[i] = 0;
        t[i] = INF;
        TATA[i] = 0;
    }

    t[s] = 0;
    TATA[s] = 0;

    while (true)
    {
        int min = INF, x = 0;

        for (int i = 1; i <= n; i++)
            if (S[i] == 0 && t[i] < min)
            {
                min = t[i];
                x = i;
            }

        if (min == INF) break;

        S[x] = 1;

        for (int i = 1; i <= n; i++)
            if (S[i] == 0 && c[x][i] < INF)
                if (t[i] > t[x] + c[x][i])
                {
                    t[i] = t[x] + c[x][i];
                    TATA[i] = x;
                }
    }

    cout << "\nDistantele minime de la nodul " << s << " la celelalte noduri:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Nod " << i << ": ";
        if (t[i] == INF)
            cout << "INF";
        else
            cout << t[i];
        cout << " (Tata: " << TATA[i] << ")\n";
    }
}

int main()
{
    f >> n >> m;

    creareMatrice(n, m, a, c);

    cout << "\nMatricea de adiacenta:\n";
    afisareMatrice(n, a);

    int start;
    cout << "\nIntroduceti nodul sursa pentru Dijkstra: ";
    cin >> start;

    Dijkstra(start);

    return 0;
}
