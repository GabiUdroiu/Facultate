#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int k, viz[100],cc[100],a[100][100],tata[100],n,m,varf,s[100],urm[100],nrc;
void viziteaza(int x)
{
    cc[x]=nrc;
}
void creareMatrice (int n, int m, int a[20][100])
{
    int x,y;
    for(int i=1; i<=m; i++)
    {
        f>>x>>y;
        a[x][y]++;
        if(x!=y)a[y][x]++;
    }
}
void df_recursiv (int x)
{
    viziteaza(x);
    viz[x]=1;
    for(int y=1; y<=n; y++)
    {
        if(a[x][y]>=1 && viz[y]==0)
        {
            tata[y]=x;
            df_recursiv(y);
        }
    }
}
void comp_conexe_neorientat ()
{
    int i;
    nrc=0;
    for(i=1; i<=n; i++)
        cc[i]=0;
    for(i=1; i<=n; i++)
        if(cc[i]==0)
        {
            nrc++;
            df_recursiv(i);
        }
}
int main()
{
    f>>n;
    f>>m;
    creareMatrice(n,m,a);
    comp_conexe_neorientat();
    cout<<"numarul de comp conexe:"<<nrc<<endl;
    k=m-n+nrc;
    cout<<"numarul ciclomatic este: "<<k<<endl;
    return 0;
}