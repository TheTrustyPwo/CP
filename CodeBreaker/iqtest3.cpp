#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << i << " " << (i % n) + 1 << endl;
    }

    // for (int i = 1; i <= n; i++) {
    //    cout << i << " " << i << endl;
    // }

    return 0;
}