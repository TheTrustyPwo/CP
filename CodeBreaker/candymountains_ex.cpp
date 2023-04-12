#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	ll a[n+1]; for (int i = 0; i < n; i++) cin >> a[i]; a[n] = 0;
	ll dp[n+2]; dp[0] = 0;
	for (int i = 1; i <= n + 1; i++) dp[i] = max(dp[i-1], a[i-1]);
	
	deque<ll> dq; dq.push_back(dp[0]);
	for (int i = 1; i <= n + 1; i++) {
		if (dq.front() < i - k && i >= k) dq.pop_front();
		dp[i] = max(dp[dq.front()], a[i-1]);
		while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
		dq.push_back(i);
	}
	cout << dp[n+1];
}
