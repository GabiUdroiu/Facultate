/*
4. Generarea combinarilor cu repetite pentru multimi oarecare
*/

#include <iostream>

using namespace std;

void afisare(int c[], int a[], int n) {
    for(int i = 1; i <= n; i++)
        cout << a[c[i]] << ' ';
    cout << '\n';
}

void combinari_cu_repetitie(int a[], int m, int n) {
    int c[100], i, j, k;
    for(i = 1; i <= n; i++)
        c[i] = 1;
    afisare(c, a, n);
    do {
        k = n;
        while(c[k] == m && k > 0) k--;
        if(k > 0) {
            c[k]++;
            for(i = k + 1; i <= n; i++)
                c[i] = c[k];
            afisare(c, a, n);
        }
    } while(k > 0);
}

int main() {
    int a[101], m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i]; //multimea
    combinari_cu_repetitie(a, m, n);
    return 0;
}