#include <iostream>
#include <climits>

using namespace std;

int s[100],cost,t[100],tata[100],minim,y,x,c[100][100],i,j,l,n,m;

int prim(int c[100][100],int n)
{
    s[1]=1;
    cost=0;
    for(i=2;i<=n;i++)
    {
       s[i]=0;
       t[i]=c[i][1];
       tata[i]=1;
    }
    for(l=1;l<=n-1;l++)
    {
        minim=999999;
        for(i=2;i<=n;i++)
            if(s[i]==0&&t[i]<minim)
        {
            minim=t[i];
            y=i;
        }
        s[y]=1;
        x=tata[y];
        cost=cost+c[x][y];
        for(i=2;i<=n;i++)
        {
            if(s[i]==0&&t[i]>c[i][y])
            {
                t[i]=c[i][y];
                tata[i]=y;
            }
        }
    }
    return cost;
}

int main()
{
    cout<<"introduceti nr de noduri: ";
    cin>>n;
    cout<<"introduceti nr de muchii: ";
    cin>>m;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        c[j][i]=((i!=j)?999999:0);

    for(i=1;i<=m;i++)
    {
        cout<<"muchia "<<i<<" si costul ei: ";
        cin>>x>>y>>cost;
        if(c[x][y]==-1)
            c[x][y]=cost;
        else
            c[x][y]=min(c[x][y],cost);
        c[y][x]=c[x][y];
    }
    cout<<prim(c,n);
    return 0;
}