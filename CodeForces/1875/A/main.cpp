#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int a, b, n; cin >> a >> b >> n;
    int c[n]; for (int i = 0; i < n; i++) cin >> c[i];
    int ans = b;
    for (int i = 0; i < n; i++) ans += min(c[i], a - 1);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
