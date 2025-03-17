/*
5. Generarea aranjamentelor cu repetitie pentru multimi standard.
*/

#include <iostream>

using namespace std;

void afisare(int c[], int n) {
    for(int i = 1; i <= n; i++)
        cout << c[i] << ' ';
    cout << '\n';
}

void aranjamente_cu_repetitie(int a[], int n, int m) {
    int c[101], k;
    for(int i = 1; i <= n; i++)
        c[i] = 1;
    afisare(c,n);
    do{
        k = n;
        while(c[k] == m && k > 0) k--;
        if(k > 0) {
            c[k]++;
            for(int i = k + 1; i <= n; i++)
                c[i] = 1;
            afisare(c,n);
        }
    } while(k > 0);
}

int main() {
    int a[101], n, m;
    cin >> n >> m;
    aranjamente_cu_repetitie(a, n, m);
    return 0;
}