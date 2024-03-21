#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k; string s;
int pos[200005], pre[200005]; vector<int> v;
int dp[200005][5];

bool check(int x) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0) { dp[i][j] = 1e9; continue; }
			if (i - x >= 1) dp[i][j] = min(dp[i - 1][j], dp[pos[i - x]][j - 1] + pre[i] - pre[i - x]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k] << ' ';
	return dp[n][k] <= m;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> k >> s;
		for (int i = n - 1; i >= 0; i--) {
			v.push_back(i + 1);
			if (s[i] == '0') {
				while (!v.empty()) {
					pos[v.back()] = i;
					v.pop_back();
				}
			}
		}
		
		pre[0] = 0;
		for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (s[i - 1] == '1');
		
		int l = 1, r = n, ans = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m)) l = m + 1, ans = l;
			else r = m - 1;
		}
		 
		cout << ans << '\n';
	}
}
