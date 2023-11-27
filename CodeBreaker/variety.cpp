#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, w;
pair<pair<int, int>, int> a[300005];
int dp[300005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> w;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		a[i].first.first = x, a[i].first.second = y;
		int c; cin >> c;
		a[i].second = c + (y - x + 1) * w;
	}
	
	sort(a, a + n);
	
	for (int i = 2; i <= m; i++) if (a[i].first.first > a[i-1].first.second) {
		cout << -1;
		return 0;
	}
	
	fill(dp, dp + n, 1e9); dp[0] = 0;
	for (int i = 0; i < m; i++) {
		int x = a[i].first.first, y = a[i].first.second, c = a[i].second;
		if (dp[x] != 1e9) dp[y] = min(dp[y], dp[x] + c);
	}
	
	cout << dp[n - 1] - n * w;
}
