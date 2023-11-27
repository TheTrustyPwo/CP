#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];
    bool dp[n + 1]; fill(dp, dp + n + 1, 0); dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i + a[i] <= n && dp[i-1]) dp[i + a[i]] = true;
        if (i - a[i] - 1 >= 0 && dp[i - a[i] - 1]) dp[i] = true;
    }
    cout << (dp[n] ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
