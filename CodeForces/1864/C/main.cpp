#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    cout << 31 + __builtin_popcount(n) - __builtin_clz(n) << '\n' << n << ' ';
    while ((n & (n - 1)) > 0) cout << (n -= (n & -n)) << ' ';
    while (n > 1) cout << (n >>= 1) << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
