#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int pre[5005], c[5005], s[5005];
int dp[5005][5005];

int cost(int l, int r) {
	int res = -(l <= 1 ? 0 : c[l] * c[l - 1]) -(r >= n ? 0 : c[r] * c[r + 1]);
	res += (pre[r] - pre[l - 1]);
	return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	pre[0] = 0; for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + s[i];
	
	cout << cost(2, 2) << '\n';
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) {
		if (i == 0 || j == 0) dp[i][j] = 0;
		dp[i][j] = dp[i - 1][j];
		for (int a = 1; a <= j; a++)
			dp[i][j] = max(dp[i][j], dp[i - a][j - a] + cost(i - a + 1, i));
	}
	
	cout << dp[n][k];
}
