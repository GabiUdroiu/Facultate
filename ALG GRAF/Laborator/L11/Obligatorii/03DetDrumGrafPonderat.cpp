#include <iostream>
#include <fstream>
#define INF 1000000
using namespace std;

ifstream f("date.in");
int a[20][100], c[100][100], n, m;
int t[100], S[100], TATA[100][100], k[100];
int drum[100], sol[100][100], ns;

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

void Dijkstra(int s)
{
    int i;
    for (i = 1; i <= n; i++) {
        S[i] = 0;
        t[i] = INF;
        k[i] = 0;
    }

    t[s] = 0;

    while (true)
    {
        int min = INF, x = 0;
        for (i = 1; i <= n; i++)
            if (S[i] == 0 && t[i] < min)
            {
                min = t[i];
                x = i;
            }

        if (min == INF) break;

        S[x] = 1;

        for (i = 1; i <= n; i++)
            if (S[i] == 0 && c[x][i] < INF)
                if (t[i] > t[x] + c[x][i])
                {
                    t[i] = t[x] + c[x][i];
                    k[i] = 0;
                    TATA[i][++k[i]] = x;
                }
                else if (t[i] == t[x] + c[x][i])
                {
                    TATA[i][++k[i]] = x;
                }
    }
}

void genereazaDrumuri(int nod, int nivel, int sursa)
{
    int i;
    drum[nivel] = nod;

    if (nod == sursa)
    {
        ns++;
        for (i = nivel; i >= 1; i--)
            sol[ns][nivel - i + 1] = drum[i];
        sol[ns][0] = nivel;
    }
    else
        for (i = 1; i <= k[nod]; i++)
            genereazaDrumuri(TATA[nod][i], nivel + 1, sursa);
}

void afisareDrumuri(int sursa, int destinatie)
{
    ns = 0;
    genereazaDrumuri(destinatie, 1, sursa);

    cout << "\nToate drumurile de cost minim (" << t[destinatie] << ") de la " << sursa << " la " << destinatie << ":\n";

    for (int i = 1; i <= ns; i++)
    {
        for (int j = 1; j <= sol[i][0]; j++)
        {
            cout << sol[i][j];
            if (j < sol[i][0]) cout << " -> ";
        }
        cout << endl;
    }
}

int main()
{
    int sursa, destinatie;

    f >> n >> m;
    creareMatrice(n, m, a, c);

    cout << "Nod sursa: ";
    cin >> sursa;
    cout << "Nod destinatie: ";
    cin >> destinatie;

    Dijkstra(sursa);
    afisareDrumuri(sursa, destinatie);

    return 0;
}
