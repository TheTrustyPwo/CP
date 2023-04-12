#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int x, y; cin >> x >> y;
    if (x == 1 && y == 1) {
        cout << "1\n1 1\n";
        return;
    }

    cout << "2\n";
    cout << 1 << ' ' << y - 1 << '\n';
    cout << x << ' ' << y << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
