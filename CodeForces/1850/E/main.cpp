#include <bits/stdc++.h>
using namespace std;
 
void test_case(int test) {
    uint64_t n, c; cin >> n >> c;
    uint64_t a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    uint64_t l = 0, r = 1e9, ans;
    while (l <= r) {
        uint64_t m = l + (r - l) / 2;
        uint64_t res = 0;
        for (uint64_t i = 0; i < n; i++) {
            res += (a[i] + m) * (a[i] + m);
            if (res > c) break;
        }
        if (res >= c) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << ans / 2 << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}