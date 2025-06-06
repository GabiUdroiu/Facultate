#include <iostream>
#include <fstream>
#define INF 1000000
using namespace std;

int c[101][101], f[101][101], VIZ[101], TATA[101], URM[101], S[101];
int n, m, x, y, cap, varf, coada;

int BFS(int s, int t)
{
    int i;
    for (i = 1; i <= n; i++) {
        VIZ[i] = 0;
        TATA[i] = 0;
        URM[i] = 0;
    }

    VIZ[s] = 1;
    varf = coada = 1;
    S[coada] = s;

    while (varf <= coada)
    {
        int nod = S[varf];
        int j = URM[nod] + 1;
        while ((c[nod][j] - f[nod][j] <= 0 || VIZ[j] == 1) && j <= n)
            j++;
        if (j > n)
            varf++;
        else
        {
            URM[nod] = j;
            VIZ[j] = 1;
            TATA[j] = nod;
            coada++;
            S[coada] = j;
        }
    }

    return VIZ[t];
}

int minFlux(int s, int t)
{
    int minF = INF;
    int i = t;
    while (i != s)
    {
        int p = TATA[i];
        if (c[p][i] - f[p][i] < minF)
            minF = c[p][i] - f[p][i];
        i = p;
    }
    return minF;
}

void updateFlux(int s, int t, int flux)
{
    int i = t;
    while (i != s)
    {
        int p = TATA[i];
        f[p][i] += flux;
        f[i][p] -= flux;
        i = p;
    }
}

int FordFulkerson(int s, int t)
{
    int flux_total = 0;
    while (BFS(s, t))
    {
        int d = minFlux(s, t);
        updateFlux(s, t, d);
        flux_total += d;
    }
    return flux_total;
}

int main()
{
    ifstream fin("date.in");
    fin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        fin >> x >> y >> cap;
        c[x][y] = cap;
    }
    int flux_maxim = FordFulkerson(1, n);
    cout << flux_maxim << "\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (f[i][j] > 0)
                cout << i << " -> " << j << " = " << f[i][j] << "\n";
}
