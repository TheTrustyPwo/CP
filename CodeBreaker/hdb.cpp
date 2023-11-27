#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l; cin >> n >> l;
	int s[n];
	vector<int> t[n];
	
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int c; cin >> c;
		for (int j = 0; j < c; j++) {
			int x; cin >> x;
			t[i].push_back(x);
		}
		sort(t[i].begin(), t[i].end());
	}
	
	t[n - 1].push_back(l);
	
	int pre[l + 5], back[l + 5];
	vector<int> dp[n]; dp[0].resize(t[0].size(), 1e18);
	for (int j = 0; j < t[0].size(); j++) dp[0][j] = s[0] * (t[0][j] - 1);
	
	if (n >= 1) {
		pre[0] = dp[0][0] - s[1] * t[0][0];
		for (int j = 1; j < t[0].size(); j++) pre[j] = min(pre[j - 1], dp[0][j] - s[1] * t[0][j]);
		
		int tmp = t[0].size() - 1;
		back[tmp] = dp[0][tmp] + s[1] * t[0][tmp];
		for (int j = tmp - 1; j >= 0; j--) back[j] = min(back[j + 1], dp[0][j] + s[1] * t[0][j]);
	}
	
	for (int i = 1; i < n; i++) {
		dp[i].resize(t[i].size(), 1e18);
		for (int j = 0; j < t[i].size(); j++) {
			dp[i][j] = 1e18;
			int cut = lower_bound(t[i - 1].begin(), t[i - 1].end(), t[i][j]) - t[i - 1].begin();
			//cout << cut << ' ' << t[i - 1].size() << '\n';
			if (t[i][j] >= t[i - 1][0]) dp[i][j] = min(dp[i][j], pre[max((long long) 0, cut - 1)] + s[i] * t[i][j]);
			if (t[i][j] <= t[i - 1].back()) dp[i][j] = min(dp[i][j], back[cut] - s[i] * t[i][j]);
			// for (int k = 0; k < t[i - 1].size(); k++)
			//	dp[i][j] = min(dp[i][j], dp[i - 1][k] + s[i] * abs(t[i][j] - t[i - 1][k]));
		}
		
		if (i < n - 1) {
			pre[0] = dp[i][0] - s[i + 1] * t[i][0];
			for (int j = 1; j < t[i].size(); j++) pre[j] = min(pre[j - 1], dp[i][j] - s[i + 1] * t[i][j]);
			
			int tmp = t[i].size() - 1;
			back[tmp] = dp[i][tmp] + s[i + 1] * t[i][tmp];
			for (int j = tmp - 1; j >= 0; j--) back[j] = min(back[j + 1], dp[i][j] + s[i + 1] * t[i][j]);
			
			// for (int j = 0; j < t[i].size(); j++) cout << pre[j] << ' '; cout << '\n';
			// for (int j = 0; j < t[i].size(); j++) cout << back[j] << ' '; cout << '\n';
		}
	}
	
	//for (int i = 0; i < n; i++) {
	//	for (const int u : dp[i]) cout << u << ' ';
	//	cout << '\n';
	//}
	
	cout << dp[n - 1].back();
}
