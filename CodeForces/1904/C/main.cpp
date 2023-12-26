#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    if (k >= 3) { cout << "0\n"; return; }
    sort(a, a + n);
    if (k == 1) {
        int mn = a[0];
        for (int i = 1; i < n; i++) mn = min(mn, a[i] - a[i - 1]);
        cout << mn << '\n';
    } else {
        int ans = a[0];
        for (int i = 1; i < n; i++) ans = min(ans, a[i] - a[i - 1]);
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            int add = abs(a[i] - a[j]);
            int loc = lower_bound(a, a + n, add) - a;
            if (loc) ans = min(ans, add - a[loc - 1]);
            if (loc < n) ans = min(ans, a[loc] - add);
        }
        cout << ans << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
