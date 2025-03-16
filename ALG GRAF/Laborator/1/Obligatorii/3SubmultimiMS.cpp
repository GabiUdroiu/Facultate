/*
Generarea submultimilor unei multimi standard.
*/

#include <iostream>

using namespace std;

void afisare(int c[], int a[], int n) {
    for(int i = 1; i <= n; i++)
        if(c[i] == 1)
            cout << a[i] <<' ';
    cout << '\n';
}

void submultimi(int a[], int n) {
    int c[101], k;
    for(int i = 1; i <= n; i++)
        c[i] = 1;
    afisare(c, a, n);
    do {
        k = n;
        while((c[k] == 2) && (k >= 0)) k--;
        if(k>=0) {
            c[k] = 2;
            for(int i = k + 1; i <= n; i++)
                c[i] = 1;
            afisare(c,a,n);
        }
    } while(k > 0);
}

int main() {
    int a[101], n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        a[i] = i;

    submultimi(a,n);
    return 0;
}
