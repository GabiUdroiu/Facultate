/*
4. Calculul numerelor P(n,k) si P(n) (tabel)
*/

#include <iostream>

using namespace std;

int contor, s;

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
    //afisare(t, k);
    contor++;
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
            //afisare(t, k);
            contor++;
        }
    } while(j > 0);
    cout << contor << ' ';
    s += contor;
    contor = 0;
}

int main() {
    int n = 7, i, j;
    for(int i = 1; i <= n; i++) { 
        for(int j = 1; j <= n; j++)
            if(j <= i)
                generare_p(i, j);
            else cout << '0' << ' ';
        cout << s;
        s = 0;
        cout << '\n';
    }
    return 0;
}

/*
1 0 0 0 0 0 0 1
1 1 0 0 0 0 0 2
1 1 1 0 0 0 0 3
1 2 1 1 0 0 0 5
1 2 2 1 1 0 0 7
1 3 3 2 1 1 0 11
1 3 4 3 2 1 1 15
*/