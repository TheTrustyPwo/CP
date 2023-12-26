#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	long double x = ((long double) a.second) / a.first;
	long double y = ((long double) b.second) / b.first;
	return x < y;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> a[i].second;
	sort(a, a + n, &cmp);
	
	pair<int, int> dp[n + 1][k + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0 || j == 0) dp[i][j] = make_pair(0, 0);
			else if (j < a[i - 1].first) dp[i][j] = dp[i - 1][j];
			else {
				int x = dp[i - 1][j].first;
				int y = dp[i - 1][j - a[i - 1].first].first + a[i - 1].second * dp[i - 1][j - a[i - 1].first].second;
				if (x > y) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = make_pair(y, j);
			}
		}
	}
	
	cout << dp[n][k].first;
}
