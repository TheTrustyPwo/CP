#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, s = 0;
pair<int, int> dp[1005][100005];
pair<int, int> a[1005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first, s += a[i].first;
	for (int i = 1; i <= n; i++) cin >> a[i].second;
	sort(a + 1, a + n + 1, [](pair<int, int> &u, pair<int, int> &v) { return u.second > v.second; });
	
	int cur = 0, x = 0;
	while (cur < s) x++, cur += a[x].second;
	
	memset(dp, 128, sizeof(dp));
	for (int i = 0; i <= n; i++) dp[i][0] = make_pair(0, 0);
	for (int i = 1; i <= n; i++) for (int k = cur; k >= a[i].second; k--) {
		dp[i][k] = max(dp[i-1][k], make_pair(dp[i-1][k-a[i].second].first - 1,
			dp[i-1][k-a[i].second].second + a[i].first));
	}
	
	int mx = 0;
	for (int i = s; i <= cur; i++) if (dp[n][i].first == -x) mx = max(mx, dp[n][i].second);
	cout << x << ' ' << s - mx;
}
