#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n + 2]; a[0] = a[n + 1] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int dp[n + 3]; dp[0] = 0;
	
	deque<int> dq; dq.push_back(dp[0]);
	for (int i = 1; i < n + 3; i++) {
		if (dq.front() < i - k && i >= k) dq.pop_front();
		dp[i] = a[i-1] + dp[dq.front()];
		while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
		dq.push_back(i);
	}
	
	cout << dp[n + 2];
}
