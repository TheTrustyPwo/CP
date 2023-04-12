#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> merge(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first) return {a.first, a.second + b.second};
	if (a.first < b.first) return a;
	else return b;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int p, s; cin >> p >> s;
	int a[s]; for (int i = 0; i < s; i++) cin >> a[i];
	
	pair<int, int> dp[s + 1][p + 1];
	for (int i = 0; i <= s; i++) {
		for (int j = 0; j <= p; j++) {
			if (i == 0 && j == 0) dp[i][j] = {0, 1};
			else if (i == 0 && j != 0) dp[i][j] = {1e9, 0};
			else if (j - a[i - 1] < 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = merge({dp[i][j - a[i - 1]].first + 1, dp[i][j - a[i - 1]].second}, dp[i - 1][j]);
		}
	}
	
	if (dp[s][p].second == 0) cout << -1;
	else cout << dp[s][p].first << endl << dp[s][p].second;
}
