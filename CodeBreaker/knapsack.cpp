#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, s, ans = 0;
ll dp[2005];
vector<pair<int, int>> a[2005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s >> n;
	for (int i = 1; i <= n; i++) {
		int v, w, k; cin >> v >> w >> k;
		a[w].push_back(make_pair(v, k));
	}
	
	for (int i = 1; i <= s; i++) {
		sort(a[i].begin(), a[i].end(), greater<pair<int, int>>());
		int index = 0;
		for (int j = 0; j < s / i; j++) {
			if (index >= (int) a[i].size()) break;
			for (int k = s; k >= i; k--) {
				dp[k] = max(dp[k], dp[k - i] + a[i][index].first);
				ans = max(ans, dp[k]);
			}
			a[i][index].second--;
			if (a[i][index].second == 0) index++;
		}
	}
	
	cout << ans;
}
