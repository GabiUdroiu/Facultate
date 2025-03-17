/*
1. Generarea combinarilor pentru multimi standard
*/
#include <iostream>
using namespace std;



void afisare(int c[], int n) {
    for(int i = 1; i <= n; i++)
        //printf("%d \n",p[i]);
        cout << c[i] << ' ';
    cout << endl;
    return;
}

void combinari(int m,int n) {
    int c[100];
    int i, j, k;
    for(i = 1; i <= n; i++)
        c[i] = i;
    afisare(c,n);
    do {
        k = n;
        while(c[k] == m-n+k && k > 0) k--;
        if(k > 0) {
            c[k] = c[k] + 1;
            for(i = k+1; i <= n; i++)
                c[i] = c[i-1] + 1;
            afisare(c,n);
        }
    } while(k > 0);
}
int main() {
    int m, n;
    cin >> m >> n;
    combinari(m,n);
    return 0;
}