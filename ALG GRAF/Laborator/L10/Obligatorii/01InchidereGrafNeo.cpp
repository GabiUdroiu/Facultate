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
        ///NEORIENTAT
        if (x != y)
            a[y][x]++;
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

int grade[100];
void calculGrade(int n, int a[20][100])
{
    for (int i = 1; i <= n; i++)
    {
        int s = 0;
        //cout << "Gradul nodului " << i << ": ";
        for (int j = 1; j <= n; j++)
            s += a[i][j];
        grade[i] = s;
        //cout << s << endl;
    }
}

void adnod(int n, int a[20][100])
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        if(a[i][i]==0)
        for (j = i+1; j <= n; j++)
            if(a[i][j]==0)
                if(grade[i]+grade[j] >= n)   {
                    cout << "Adaug: " << i << ' ' << j <<endl;
                    grade[i]++;
                    grade[j]++;
                    //a[i][i]++;
                    a[i][j]++;
                    a[j][i]++;
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
    //afisareMatrice(n,a);
    calculGrade(n, a);
    adnod(n,a);
    afisareMatrice(n,a);
}
/*
6
9
1 2
2 3
3 4
4 5
5 6
6 1
6 4
4 1
1 3
*/