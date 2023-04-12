#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, p, q, e[2005], dp[2005][2005];

bool valid(int w) {
	for (int i = 0; i < n; i++) {
		int s = (int) (upper_bound(e, e + n, e[i] - w) - e) - 1;
		int b = (int) (upper_bound(e, e + n, e[i] - 2 * w) - e) - 1;
		dp[i][0] = 1 + (s < 0 ? 0 : dp[s][0]);
		for (int j = 1; j <= q; j++)
			dp[i][j] = (b < 0 ? 0 : min(dp[b][j - 1], dp[s][j] + 1));
	}
	
	return dp[n - 1][q] <= p;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> p >> q;
	for (int i = 0; i < n; i++) cin >> e[i];
	sort(e, e + n);
	
	if (p + q >= n) { cout << 1; return 0; }
	
	int l = 1, r = 1e9;
	while (l < r) {
		int m = (l + r) >> 1;
		if (valid(m)) r = m;
		else l = m + 1;
	}
	
	cout << l;
}
