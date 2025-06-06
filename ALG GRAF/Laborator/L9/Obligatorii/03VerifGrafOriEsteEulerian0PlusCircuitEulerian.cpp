#include <iostream>
using namespace std;

int a[20][100],gradIn[100], gradOut[100], n, m;

void creareMatrice(int n, int m, int a[20][100]) {
    int x, y, cost;
    for (int i = 1; i <= m; i++) {
        cout << "Dati extremitatile muchiei " << i << ": ";
        cin >> x >> y;
        a[x][y]++;
    }
}

bool esteEulerianOrientat() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j]) {
                gradOut[i] += a[i][j];
                gradIn[j] += a[i][j];
            }

    for (int i = 1; i <= n; i++)
        if (gradIn[i] != gradOut[i])
            return false;

    return true;
}

int main() {
    cout << "Nr. noduri: ";
    cin >> n;
    cout << "Nr. muchii: ";
    cin >> m;

    creareMatrice(n, m, a);

    if (esteEulerianOrientat())
        cout << "Graful orientat are circuit eulerian.\n";
    else
        cout << "Graful orientat NU are circuit eulerian.\n";

    return 0;
}
