/*
5. Generarea partitiilor multimi {1,2,...,n} cu k parti
*/

#include <iostream>

using namespace std;

int v[101], n, k;

void afisare(int v[]) {
    int i, j;
    for (j = 1; j <= k; j++){
        cout << "{";
        for (i = 1; i <= n; i++)
            if (v[i] == j)
                cout << i << ' ';
        cout << "} ";
    }
    cout << endl;
}

void Generare_S(int n, int k) {
    if (k == 1) {
        for(int i = 1; i <= n; i++)
            v[i] = 1;
        afisare(v);
    }
    else {
        if(k == n) {
            for(int i = 1; i <= n; i++)
                v[i] = i;
            afisare(v);
        }
        else {
            v[n] = k;
            Generare_S(n - 1, k - 1);
            for(int i = 1; i <= k; i++) {
                v[n] = i;
                Generare_S(n - 1, k);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    Generare_S(n, k);
}
