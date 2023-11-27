#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, x; cin >> n >> x;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int l = 1, r = 2e9, ans;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int res = 0;
        for (int i = 0; i < n; i++) res += max(m - a[i], (long long) 0);
        if (res <= x) ans = m, l = m + 1;
        else r = m - 1;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
