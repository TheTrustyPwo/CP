#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n+1]; for (int i = 1; i <= n; i++) cin >> a[i];
    int dp[n+1]; dp[0] = 0;
    int mx[n+1]; fill(mx, mx + n + 1, -1e9);
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1], mx[a[i]]+i+1);
        mx[a[i]] = max(mx[a[i]], dp[i-1] - i);
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
