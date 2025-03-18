/*
2. Generarea compunerilor lui n cu m termeni nenuli
*/

#include <iostream>

using namespace std;

void afisare(int t[], int m) {
    cout << t[1];
    for(int i = 2; i <= m; i++)
        cout << '+' << t[i];
    cout << '\n';
}

void compuneri_termeni_nenuli(int n, int m) {
    int t[101], k;
    for(int i = 1; i <= m-1; i++)
        t[i] = 1;
    t[m] = n - m + 1;
    afisare(t, m);
    do {
        k = m;
        while(t[k] == 1 && k > 1) k--;
        if(k > 1) {
            t[k - 1] = t[k - 1] + 1;
            t[m] = t[k] - 1;
            if(k < m) t[k] = 1;
            afisare(t, m);
        }
    } while(k > 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    compuneri_termeni_nenuli(n, m);
    return 0;
}