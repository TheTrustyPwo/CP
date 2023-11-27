#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    bool v[n]; v[0] = 0;
    for (int i = 1; i < n; i++) v[i] = (a[i] - a[i - 1]) <= k;
    int cur = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (!v[i] || i == n) {
            mx = max(cur, mx);
            cur = 0;
        } else cur++;
    } mx = max(mx, cur);
    cout << n - mx - 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
