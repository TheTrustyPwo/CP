#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int c[5005], s[5005];
int dp[5005][5005][2];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k; c[0] = c[n + 1] = 0;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) for (int f = 1; f >= 0; f--) {
		if (i == 0 && f == 0) dp[i][j][f] = 0;
		else if (i == 0 && f == 1) dp[i][j][f] = -1e18;
		else if (f == 1) dp[i][j][f] = max(dp[i-1][j-1][0]+s[i]-c[i]*c[i-1], dp[i-1][j-1][1]+s[i]);
		else if (f == 0) dp[i][j][f] = max(dp[i-1][j][0], dp[i][j][1]-c[i]*c[i+1]);
	}
	
	cout << dp[n][k][0];
}
