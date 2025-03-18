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
    cout << endl;
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
