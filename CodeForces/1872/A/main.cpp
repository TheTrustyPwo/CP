#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int a, b, c; cin >> a >> b >> c;
    int diff = (abs(a - b) + 1) / 2;
    if (diff == 0) { cout << 0 << '\n'; return; }
    int ans = (diff / c) + (diff % c != 0);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
