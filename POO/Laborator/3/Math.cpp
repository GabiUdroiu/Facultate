#include <iostream>

using namespace std;

class Math {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

int main() {
    int sum = Math::add(5, 3);
    cout << "Suma: " << sum << endl;
    return 0;
}