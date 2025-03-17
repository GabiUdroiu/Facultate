/*
7. Generarea aranjamentelor pentru multimi oarecare
*/

#include <iostream>

using namespace std;


void afisare(int c[], int p[], int n) {
    for(int i = 1; i <= n; i++)
        cout << c[p[i]] << ' ';
    cout << '\n';
}

void permutari(int a[], int n) {
    int p[101], i, j, k;
    for(i = 1; i <= n; i++)
        p[i] = i;
    afisare(a, p, n);
    do {
        k = n - 1;
        while(p[k] >= p[k+1] && k > 0) k--;
        if(k > 0) {
            j = n;
            while(p[j] <= p[k]) j--;
            swap(p[k], p[j]);
            for(i = 1; i <= (n-k)/2; i++)
                swap(p[k+i], p[n-i+1]);
            afisare(a, p, n);
        }
    } while(k > 0);
}

void aranjamente(int c[], int m, int n) {
    int a[101], i, j, k;
    for(i = 1; i <= n; i++)
        a[i] = i;
    do {
        int b[101];
        for (i = 1; i <= n; i++)
            b[i] = c[a[i]];
        permutari(b, n);
        k = n;
        while(a[k] == m-n+k && k > 0) k--;
        if(k > 0) {
            a[k]++;
            for(i = k + 1; i <= n; i++)
                a[i] = a[i-1] + 1;
        }
    } while(k > 0);
}

int main() {
    int a[101], m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    aranjamente(a, m, n);
    return 0;
}