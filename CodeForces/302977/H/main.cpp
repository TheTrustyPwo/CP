#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int s[n + 1]; s[0] = 0; for (int i = 1; i <= n; i++) cin >> s[i];
    int c[n + 1]; for (int i = 1; i <= n; i++) cin >> c[i];

    int dp[n + 1][4];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= 3; j++) dp[i][j] = 1e18; dp[0][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= 3; j++) {
        int mn = 1e18;
        for (int k = 0; k < i; k++) if (s[i] > s[k]) mn = min(mn, c[i] + dp[k][j - 1]);
        dp[i][j] = mn;
    }

    int mn = 1e18; for (int i = 0; i <= n; i++) mn = min(dp[i][3], mn);
    cout << (mn == 1e18 ? -1 : mn);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
