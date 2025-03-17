/*
5. Generarea permutarilor cu repetitie pentru multimi oarecare
*/

#include <iostream>

using namespace std;

void afisare(int p[],int a[], int n) {
    for(int i = 1; i <= n; i++)
        cout << a[p[i]] << ' ';
    cout << '\n';
}

void permutari_cu_repetitie(int a[], int n, int t[], int m) {
    int p[101], i, j, k;
    n = 0;
    for(i = 1; i <= m; i++) n += t[i];
    i = 0;
    for(j = 1; j <= m; j++){
        for(k = 1; k <= t[j]; k++) {
            i++;
            p[i] = j;
        }
    }
    afisare(p, a, n);
    do {
        k = n - 1;
        while(p[k] >= p[k+1] && k > 0) k--;
        if(k > 0) {
            j = n;
            while(p[j] <= p[k]) j--;
            swap(p[k], p[j]);
            for(i = 1; i <= (n-k)/2; i++)
                swap(p[k+i], p[n-i+1]);
            afisare(p, a, n);
        }
    } while(k > 0);
}

int main() {
    int a[101], t[101], n, m;
    cin >> n; // Nr de elem
    for(int i = 1; i <= n; i++)
        cin >> a[i]; // Elementele
    cin >> m; // Nr de repetitii
    for(int i = 1; i <= m; i++)
        cin >> t[i]; // Repetitiile
    permutari_cu_repetitie(a, n, t, m);
    return 0;
}