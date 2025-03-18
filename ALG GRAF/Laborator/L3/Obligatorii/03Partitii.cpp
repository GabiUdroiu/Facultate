/*
3. Generarea partitilor lui n cu k termeni
*/

#include <iostream>

using namespace std;

void afisare(int t[], int m) {
    cout << t[1];
    for(int i = 2; i <= m; i++)
        cout << '+' << t[i];
    cout << '\n';
}

void generare_p(int n, int k) {
    int t[101], j, r;
    for(int i = 1; i <= k-1; i++)
        t[i] = 1;
    t[k] = n - k + 1;
    afisare(t, k);
    do {
        j = k - 1;
        while(t[j] > t[k] - 2 && j > 0) j--;
        if(j > 0) {
            t[j]++;
            for(int i = j + 1; i <= k - 1; i++)
                t[i] = t[j];
            r = 0;
            for(int i = 1; i <= k - 1; i++)
                r = r + t[i];
            t[k] = n - r;
            afisare(t, k);
        }
    } while(j > 0);
}

int main() {
    int n, m;
    cin >> n >> m;
    generare_p(n, m);
    return 0;
}