#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << (2 * i) % n + 1 << ' ' << (2 * i + 1) % n + 1 << endl;
    }
}
