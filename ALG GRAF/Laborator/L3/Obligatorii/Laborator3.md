```cpp
/*
1. Generarea compunerilor lui n cu m termeni
*/

#include <iostream>

using namespace std;

void afisare(int t[], int m) {
    cout << t[1];
    for(int i = 2; i <= m; i++)
        cout << '+' << t[i];
    cout << '\n';
}

void compuneri(int n, int m) {
    int t[101], k;
    for(int i = 1; i <= m-1; i++)
        t[i] = 0;
    t[m] = n;
    afisare(t, m);
    do {
        k = m;
        while(t[k] == 0 && k > 1) k--;
        if(k > 1) {
            t[k - 1] = t[k - 1] + 1;
            t[m] = t[k] - 1;
            if(k < m) t[k] = 0;
            afisare(t, m);
        }
    } while(k > 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    compuneri(n, m);
    return 0;
}
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
    cout << '\n';
}

void generare_S(int n, int k) {
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
            generare_S(n - 1, k - 1);
            for(int i = 1; i <= k; i++) {
                v[n] = i;
                generare_S(n - 1, k);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    generare_S(n, k);
}
/*
6. Calculul numerelor S(n,k) si Bn (tabel)
*/

#include <iostream>
#include <iomanip>

using namespace std;

int v[101], n, k, s, contor;

void afisare(int v[]) {
    int i, j;
    for (j = 1; j <= k; j++){
        cout << "{";
        for (i = 1; i <= n; i++)
            if (v[i] == j)
                cout << i << ' ';
        cout << "} ";
    }
    cout << '\n';
}

void generare_s(int n, int k) {
    if (k == 1) {
        for(int i = 1; i <= n; i++)
            v[i] = 1;
        //afisare(v);
        contor++;
    }
    else {
        if(k == n) {
            for(int i = 1; i <= n; i++)
                v[i] = i;
            ///afisare(v);
            contor++;
        }
        else if(n > 0){
            v[n] = k;
            generare_s(n - 1, k - 1);
            for(int i = 1; i <= k; i++) {
                v[n] = i;
                generare_s(n - 1, k);
            }
        }
    }
}

int main() {
    int n = 6, i, j;
    cout << setw(5) << "S(n,k)";
    for(int i = 0; i <= n; i++) //opt
        cout << setw(5) << "k=" << i; //opt
    cout << setw(7) << "Bn\n"; //opt
    cout << setfill('_') << setw(55) << "" << setfill(' ') << "\n"; //opt
    for(int i = 0; i <= n; i++) { 
        cout << "n=" << i << " | "; //opt
        for(int j = 0; j <= n; j++)
            if(j <= i) {
                generare_s(i, j);
                cout << setw(5) << contor << ' ';
                s += contor;
                contor = 0;
            }
            else cout << setw(5) << '0' << ' ';
        cout << setw(5) << "| " << s;
        s = 0;
        cout << '\n';
    }
    cout << setfill('_') << setw(55) << "" << setfill(' ') << "\n";//opt
}
```