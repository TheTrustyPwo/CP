#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int x, y, k; cin >> x >> y >> k;
    if (x > y) {
        cout << x << '\n';
    } else {
        int a = x + k;
        if (a >= y) cout << y << '\n';
        else cout << 2 * y - a << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
