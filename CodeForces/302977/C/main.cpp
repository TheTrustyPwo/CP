#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n][2];
    for (int i = 0; i < n; i++) {
        int x; cin >> x; string s; cin >> s;
        int a1 = s.find('A') != string::npos;
        int b = s.find('B') != string::npos;
        int c = s.find('C') != string::npos;
        a[i][0] = x;
        a[i][1] = a1 + 2 * b + 4 * c;
    }

    int dp[n + 1][8]; for (int i = 0; i <= n; i++) for (int j = 0; j < 8; j++) dp[i][j] = 2e9; dp[0][0] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < 8; j++) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j | a[i][1]] = min(dp[i + 1][j | a[i][1]], dp[i][j] + a[i][0]);
    }
    
    if (dp[n][7] == 2e9) cout << -1;
    else cout << dp[n][7];
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
