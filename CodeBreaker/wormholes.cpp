#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int dp[n]; dp[0] = 0; dp[1] = 1;
	
	vector<int> h[n];
	
	int w, a, b; cin >> w;
	while (w--) {
		cin >> a >> b;
		h[b].push_back(a);
	}
	
	for (int i = 2; i < n; i++) {
		dp[i] = dp[i-1] + 1;
		for (const auto a : h[i]) dp[i] = min(dp[i], 1 + dp[a]);
	}
	
	cout << dp[n-1];
}
