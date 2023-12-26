#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, q; cin >> n >> q;
    int t[n], a[n]; for (int i = 0; i < n; i++) cin >> t[i];
    while (q--) {
        int x; cin >> x; int ans = 0; for (int i = 0; i < n; i++) a[i] = t[i];
        for (int b = 60; b >= 0; b--) {
            int cur = 0, v = (1LL << b);
            for (int i = 0; i < n; i++) if (!(a[i] & v)) {
                cur += (v - (a[i] % v));
                if (cur > x) break;
            }
            if (cur > x) continue;
            x -= cur;
            ans += v;
            for (int i = 0; i < n; i++) if (!(a[i] & v)) a[i] += (v - (a[i] % v));
        }
        cout << ans << '\n';
    }
};

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
