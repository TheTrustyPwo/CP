#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int x; for (int i = 0; i < n; i++) cin >> x;
    if (n & 1) {
        cout << 4 << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 2 << ' ' << n << '\n';
        cout << 1 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    } else {
        cout << 2 << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 1 << ' ' << n << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
