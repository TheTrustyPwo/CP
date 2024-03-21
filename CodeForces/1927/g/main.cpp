#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];

    int dp[n + 1][n + 1][n + 1];
    for (int i = 1; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k <= n; k++) {
        int ai = a[i];
        {
            int nj = j > 0 ? j + 1 : 0;
            int nk = max(0, k - 1);
            dp[i + 1][nj][nk] = min(dp[i + 1][nj][nk], dp[i][j][k]);
        }
        {
            int nj = j > 0 ? j + 1 : 0;
            if (nj <= ai) nj = 0;
            int nk = max(0, k - 1);
            dp[i + 1][nj][nk] = min(dp[i + 1][nj][nk], dp[i][j][k] + 1);
        }
        {
            int nj = j > 0 ? j + 1 : 0;
            int nk = max(a[i], k - 1);
            dp[i + 1][nj][nk] = min(dp[i + 1][nj][nk], dp[i][j][k] + 1);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
