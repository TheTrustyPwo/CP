#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; fill(a, a + n, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x < n) a[x]++;
    }

    int m = 0; while (a[m]) m++;
    int dp[m + 1]; fill(dp, dp + m, 1e18); dp[m] = 0;
    for (int i = m; i >= 1; i--) for (int j = 0; j < i; j++) dp[j] = min(dp[j], dp[i] + i * a[j]);
    cout << dp[0] - m << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
