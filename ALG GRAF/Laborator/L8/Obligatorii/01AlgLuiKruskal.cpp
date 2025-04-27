#include <iostream>
#include <fstream>

using namespace std;
///Algoritmul lui Kruskal

ifstream f("date.in");

int S[100],CC[100];
int p[4][100];
int i,l,cost;
int n,m;


void afis(int M[100][100])
{
    for(l = 1; l <= 3; l++)
    {
        for(i = 1; i <= m; i++)
            cout<<M[l][i]<<"  ";
        cout<<endl;
    }

}


void CREARE_MATRICE(int &n, int &m, int p[4][100])
{
    f>>n>>m;
    for(i = 1; i <= m; i++)
        f>>p[1][i]>>p[2][i]>>p[3][i];
}

void SORTARE(int p[4][100])
{
    for(i = 1; i < m; i++)
      for(l = i+1; l <= m; l++)
        if(p[3][i] > p[3][l])
        {
            swap(p[1][i],p[1][l]);
            swap(p[2][i],p[2][l]);
            swap(p[3][i],p[3][l]);
        }
}

void KRUSKAL()
{
    int x,y,c,k;
    int aux;
    SORTARE(p);

    for( i = 1; i <= m; i++) S[i]=0;
    for( i = 1; i <= n; i++) CC[i]=i;
    cost = 0;
    int poz = 0;
    for( l = 1; l <= n-1; l++)
    {
        k = poz;
        do
        {
            k++;
            x = p[1][k];
            y = p[2][k];
            c = p[3][k];
        }while(CC[x]==CC[y]);
        S[k] = 1;
        cost += c;
        poz = k;
        aux = CC[y];
        for( i = 1; i <= n; i++)
            if(CC[i] == aux)
                CC[i] = CC[x];
    }
}

int main()
{
    /// n - nr de noduri
    /// m - nr de muchii
    CREARE_MATRICE(n,m,p);
    afis(p);
    KRUSKAL();
    cout<<endl;
    afis(p);
    cout<<endl<<cost;
    return 0;
}