/*
7. Generarea aranjamentelor pentru multimi standard
*/

#include <iostream>

using namespace std;


void afisare(int c[], int p[], int n) {
    for(int i = 1; i <= n; i++)
        cout << c[p[i]] << ' ';
    cout << '\n';
}

void permutari(int c[], int n) {
    int p[101], i, j, k;
    for(i = 1; i <= n; i++)
        p[i] = i;
    afisare(c, p, n);
    do {
        k = n - 1;
        while(p[k] >= p[k+1] && k > 0) k--;
        if(k > 0) {
            j = n;
            while(p[j] <= p[k]) j--;
            swap(p[k], p[j]);
            for(i = 1; i <= (n-k)/2; i++)
                swap(p[k+i], p[n-i+1]);
            afisare(c, p, n);
        }
    } while(k > 0);
}

void aranjamente(int m, int n) {
    int a[101], i, j, k;
    for(i = 1; i <= n; i++)
        a[i] = i;
    permutari(a, n);
    do {
        k = n;
        while(a[k] == m-n+k && k > 0) k--;
        if(k > 0) {
            a[k]++;
            for(i = k + 1; i <= n; i++)
                a[i] = a[i-1] + 1;
            permutari(a, n);
        }
    } while(k > 0);
}

int main() {
    int m, n;
    cin >> m >> n;
    aranjamente(m, n);
    return 0;
}