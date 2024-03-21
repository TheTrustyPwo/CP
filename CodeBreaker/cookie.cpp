#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v; int dp[11], a[11];

int solve(vector<int> &vec) {
	if (vec.size() == 1) return dp[vec[0]];
	else if (vec.size() == 2) return dp[vec[0]] + dp[vec[1]];
	
	int ans = 0;
	for (int i = 0; i < vec.size(); i++) {
		vector<int> tmp(vec); int e = tmp[i];
		if (i > 0 && i < (vec.size() - 1)) {
			tmp[i - 1] += tmp[i + 1];
			tmp.erase(tmp.begin() + i + 1);
		}
		tmp.erase(tmp.begin() + i);
		ans = max(ans, dp[e] + solve(tmp));
	}
	
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; string s; cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = a[i];
		for (int j = 1; j < i; j++) dp[i] = max(dp[i], dp[j] + a[i - j]);
	}
	
	int cur = 0; char c = s[0];
	for (int i = 0; i < n; i++) {
		if (s[i] == c) cur++;
		if (s[i] != c) {
			v.push_back(cur);
			cur = 1;
			c = s[i];
		}
	}
	v.push_back(cur);
	
	cout << solve(v);
}
