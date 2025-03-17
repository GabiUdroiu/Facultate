/*
3. Generarea combinarilor cu repetite pentru multimi standard
*/

#include <iostream>

using namespace std;

void afisare(int c[], int n) {
    for(int i = 1; i <= n; i++)
        cout << c[i] << ' ';
    cout << '\n';
    return;
}

void combinari_cu_repetitie(int m, int n) {
    int c[100], i, j, k;
    for(i = 1; i <= n; i++)
        c[i] = 1;
    afisare(c, n);
    do {
        k = n;
        while(c[k] == m && k > 0) k--;
        if(k > 0) {
            c[k]++;
            for(i = k + 1; i <= n; i++)
                c[i] = c[k];
            afisare(c, n);
        }
    } while(k > 0);
}

int main() {
    int a[101], m, n;
    cin >> m >> n;
    combinari_cu_repetitie(m, n);
    return 0;
}