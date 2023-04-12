#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, q; cin >> n >> q;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    for (int i = 1; i < n; i++) a[i] += a[i - 1];

    while (q--) {
        int b; cin >> b;
        int ans = distance(a, lower_bound(a, a + n, b));
        if (ans == n) cout << -1 << '\n';
        else cout << ans + 1 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
