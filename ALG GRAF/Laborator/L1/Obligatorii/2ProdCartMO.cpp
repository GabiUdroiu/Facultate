/*
2. Generarea produsului cartezian pentru multimi oarecare.
*/

#include <iostream>

using namespace std;

int a[101][101];

void afisare(int c[], int a[][101], int n) {
    for(int i = 1; i <= n; i++)
        cout << a[i][c[i]] << ' ';
    cout << '\n';
}

void produs_cartezian(int m[], int n) {
    int c[101], k;
    for(int i = 1; i <= n; i++)
        c[i] = 1;
    afisare(c,a,n);
    do{
        k = n;
        while(c[k] == m[k] && k > 0) k--;
        if(k > 0) {
            c[k]++;
            for(int i = k + 1; i <= n; i++)
                c[i] = 1;
            afisare(c,a,n);
        }
    } while(k > 0);
}

int main() {
    int m[101], n;
    cout << "Nr multimi: ";
    cin >> n;
    cout << "Nr elemente multimi: ";
    for(int i = 1; i <= n; i++)
        cin >> m[i];   
    cout << "Elementele multimilor: ";
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m[i]; j++)
            cin >> a[i][j];
    produs_cartezian(m,n);
    return 0;
}