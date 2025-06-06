#include <iostream>

using namespace std;

int n, m, a[20][100];

void creareMatrice(int n, int m, int a[20][100])
{
    int x, y;
    for(int i = 1; i <= m; i++)
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
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int grade[100];
void calculGrade(int n, int a[20][100])
{
    for(int i = 1; i <= n; i++)
    {
        int s = 0;
        //cout << "Gradul nodului " << i << ": ";
        for(int j = 1; j <= n; j++)
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
        for(j = i+1; j <= n; j++)
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

bool esteComplet(int n, int a[20][100]) {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j && a[i][j] == 0)
                return false;
    return true;
}

bool Dirac(int n, int grade[]) {
    for(int i = 1; i <= n; i++)
        if(grade[i] < n / 2)
            return false;
    return true;
}

bool Ore(int n, int a[20][100], int grade[]) {
    for(int u = 1; u <= n; u++) {
        for(int v = u + 1; v <= n; v++) {
            if(a[u][v] == 0) {
                if(grade[u] + grade[v] < n)
                    return false;
            }
        }
    }
    return true;
}

void bubbleSort(int grade[], int n, int sorted[]) {
    for(int i = 1; i <= n; i++)
        sorted[i] = grade[i];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
}

bool Posa(int n, int grade[]) {
    int d[100];
    bubbleSort(grade, n, d);

    for(int k = 1; k <= n / 2; k++) {
        if(!(d[k] >= k + 1 || d[n - k + 1] >= n - k))
            return false;
    }
    return true;
}

bool Chvatal(int n, int grade[]) {
    int d[100];
    bubbleSort(grade, n, d);
    for(int k = 1; k <= n / 2; k++) {
        if(!(d[k] >= k + 1 || d[n - k] <= n - k - 1))
            return false;
    }
    return true;
}

bool Bondy(int n, int a[20][100], int grade[]) {
    for(int u = 1; u <= n; u++) {
        for(int v = u + 1; v <= n; v++) {
            if(a[u][v] == 0) {
                if(grade[u] + grade[v] < n - 1)
                    return false;
            }
        }
    }
    return true;
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
    //adnod(n,a);
    afisareMatrice(n,a);
    cout<<"\nConditii Hamiltoniene -----------------------\n";
    cout<< (esteComplet(n,a) ? "Este complet\n" : "Nu este Complet\n");
    cout<< (Dirac(n,grade) ? "Dirac adevarat\n" : "Dirac fals\n");
    cout<< (Ore(n,a,grade) ? "Ore adevarat\n" : "Ore fals\n");
    cout<< (Posa(n,grade) ? "Posa adevarat\n" : "Posa fals\n");
    cout<< (Chvatal(n,grade) ? "Chvatal adevarat\n" : "Chvatal fals\n");
    cout<< (Bondy(n,a,grade) ? "Bondy adevarat\n" : "Bondy fals\n");
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