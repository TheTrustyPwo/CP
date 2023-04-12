#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int r, c; cin >> r >> c;
	int dp[26][26]; dp[1][1] = 1;
	for (int i = 2; i <= 25; i++) {
		dp[i][1] = dp[i-1][1];
		dp[i][i] = dp[i-1][i-1];
		for (int j = 2; j < i; j++) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	}
	cout << dp[r][c];
}
