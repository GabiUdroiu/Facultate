#include <iostream>
using namespace std;

int a[20][100],gradIn[100], gradOut[100], n, m;

void creareMatrice(int n, int m, int a[20][100]) {
    int x, y;
    for (int i = 1; i <= m; i++) {
        cout << "Dati extremitatile muchiei " << i << ": ";
        cin >> x >> y;
        a[x][y]++;
    }
}

bool areDrumEulerianDeschisOrientat() {

    int start = 0, end = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j]) {
                gradOut[i] += a[i][j];
                gradIn[j] += a[i][j];
            }

    for (int i = 1; i <= n; i++) {
        if (gradOut[i] - gradIn[i] == 1)
            start++;
        else if (gradIn[i] - gradOut[i] == 1)
            end++;
        else if (gradIn[i] != gradOut[i])
            return false;
    }

    return (start == 1 && end == 1);
}

int main() {
    cout << "Nr. noduri: ";
    cin >> n;
    cout << "Nr. muchii: ";
    cin >> m;

    creareMatrice(n, m, a);

    if (areDrumEulerianDeschisOrientat())
        cout << "Graful orientat are drum eulerian deschis.\n";
    else
        cout << "Graful orientat NU are drum eulerian deschis.\n";

    return 0;
}
