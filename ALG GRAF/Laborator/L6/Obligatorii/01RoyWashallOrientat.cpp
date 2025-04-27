#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int a[20][100],d[100][100],n,m;
void creareMatrice (int n, int m, int a[20][100])
{
    int x,y;
    for(int i=1; i<=m; i++)
    {
        cout<<"dati extremitatile muchiei "<<i<<": "<<endl;
        f>>x>>y;
        a[x][y]++;
    }
}
void afisareMatrice(int n, int a[20][100])
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
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
                d[i][j] = (d[i][j] | d[i][k] & d[k][j]);
}
int main()
{

    cout<<"nr de noduri: ";
    f>>n;
    cout<<"nr de muchii: ";
    f>>m;
    creareMatrice(n,m,a);
    afisareMatrice(n,a);
    cout<<endl;
    ROY_WARSHALL();
    afisareMatrice(n,d);
    return 0;
}