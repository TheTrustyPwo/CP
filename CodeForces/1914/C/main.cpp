#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int b[n]; for (int i = 0; i < n; i++) cin >> b[i];

    int sum = 0, ans = 0, mx = 0;
    for (int i = 0; i < min(n, k); i++) {
        mx = max(mx, b[i]);
        sum += a[i];
        ans = max(ans, sum + mx * (k - i - 1));
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
