#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

vector<long long> di(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            factorization.push_back(d);
            factorization.push_back(n / d);
        }
    }
    if (n > 1) factorization.push_back(n);
    return factorization;
}

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> v = di(n); v.push_back(1);
    int pre[n + 1]; pre[0] = 0; int ans = 0;
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i - 1];
    for (const int u : v) {
        int mn = 1e18, mx = 0;
        for (int i = 0; i <= n - u; i += u) {
            int cur = pre[i + u] - pre[i];
            // cout << i << ' ' << i + u << ' ' << cur << '\n';
            mn = min(mn, cur);
            mx = max(mx, cur);
        }
        if (mx - mn < 1e18) ans = max(ans, mx - mn);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
