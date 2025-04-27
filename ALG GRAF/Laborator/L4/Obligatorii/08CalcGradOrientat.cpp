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

void calculGrade(int n, int a[20][100])
{
    for (int i = 1; i <= n; i++)
    {
        int s = 0, gin = 0, gout = 0;
        for (int j = 1; j <= n; j++) {
            gin += a[i][j];
            gout += a[j][i];
        }
        s = gin + gout;
        cout << "Gradul de intrare al nodului " << i << ": " << gin << endl;
        cout << "Gradul de iesire al nodului " << i << ": " << gout << endl;
        cout << "Gradul total al nodului " << i << ": " << s << endl;
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
    calculGrade(n, a);
}
