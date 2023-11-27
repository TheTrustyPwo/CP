#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k, p; cin >> n >> k >> p;
    int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];
    int b[k + 1]; for (int i = 1; i <= k; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);

    int dp[n + 1][k + 1]; for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][j] = 1e12;
    for (int j = 0; j <= k; j++) dp[0][j] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= k; j++) {
        dp[i][j] = min(dp[i][j - 1], max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - p)));
    }

    cout << dp[n][k];
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
