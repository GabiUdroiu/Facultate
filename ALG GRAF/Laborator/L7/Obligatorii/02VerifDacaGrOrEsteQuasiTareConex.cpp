#include <iostream>
#include <fstream>
using namespace std;

//Verificarea daca un graf orientat dat este sau nu quasi-tare conex.

ifstream f("date.in");

int n,m;
int d[100][100];
int a[100][100];
void creareMatrice(int n, int m, int a[100][100])
{
    int x,y;
    for(int i = 1; i <= m; i++)
    {
        f>>x>>y;
        a[x][y]++;
        //pt neorientat
    }
}

void afisareMatrice(int n, int a[100][100])
{
    for(int i=1; i <= n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}

void ROY_WARSHALL()
{
    int i,j,k;

    for(i = 1 ; i<=n; i++)
        for(j = 1 ; j<=n; j++)
            d[i][j]=a[i][j];
    for(k = 1 ; k<=n; k++)
        for(i = 1 ; i<=n; i++)
            for(j = 1 ; j<=n; j++)
                d[i][j] = d[i][j] | d[i][k] & d[k][j];

}

int quasiTareConex()
{
    int i,j;
    bool ok;
    for(i=1;i<=n;i++)
    {
        ok= true;
        for(j=1;j<=n;j++)
            if(i!=j && !d[i][j])
        {
            ok=false;
            break;
        }
        if(ok) return 1;
    }
    return 0;
}

int main()
{
    f>>n>>m;
    creareMatrice(n,m,a);
    afisareMatrice(n,a);
    cout<<'\n';
    ROY_WARSHALL();
    afisareMatrice(n,d);

    bool q = quasiTareConex();
    if(q)
        cout<<"Graful este quasi-tare conex";
    else
        cout<<"Graful nu este quasi-tare conex";
    return 0;
}
