/*
6. Generarea permutarilor pentru multimi oarecare
*/

#include <iostream>

using namespace std;

void afisare(int p[], int a[], int n) {
    for(int i = 1; i <= n; i++)
        cout << a[p[i]] << ' ';
    cout << '\n';
}

void permutari(int a[], int n) {
    int p[101], i, j, k;
    for(i = 1; i <= n; i++)
        p[i] = i;
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
    int a[101], n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    permutari(a, n);
    return 0;
}