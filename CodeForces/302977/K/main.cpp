#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9 + 7;

void test_case(int test) {
    int n, k; cin >> n >> k;
    int dp[n + 1][k + 1]; memset(dp, 0, sizeof(dp)); dp[1][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 0; j < k; j++) {
        for (int a = i; a <= n; a += i) dp[a][j + 1] = (dp[a][j + 1] + dp[i][j]) % m;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dp[i][k]) % m;
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
