#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];
    int dp[n + 1][2]; dp[0][0] = 0, dp[0][1] = -1e18;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = -1e18, dp[i][1] = -1e18;
        if (i % 2 == 0) {
            dp[i][1] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
            dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
        } else {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
        }
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        dp[i][1] = max(dp[i][1], dp[i - 1][1]);
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
