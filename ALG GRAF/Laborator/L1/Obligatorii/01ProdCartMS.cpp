/*
1. Generarea produsului cartezian pentru multimi standard.
*/

#include <iostream>

using namespace std;

void afisare(int c[], int n) {
    for(int i = 1; i <= n; i++)
        cout << c[i] << ' ';
    cout << '\n';
}

void produs_cartezian(int m[], int n) {
    int c[101], k;
    for(int i = 1; i <= n; i++)
        c[i] = 1;
    afisare(c,n);
    do{
        k = n;
        while(c[k] == m[k] && k > 0) k--;
        if(k > 0) {
            c[k]++;
            for(int i = k + 1; i <= n; i++)
                c[i] = 1;
            afisare(c,n);
        }
    } while(k > 0);
}

int main() {
    int m[101], n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> m[i];
    produs_cartezian(m,n);
    return 0;
}