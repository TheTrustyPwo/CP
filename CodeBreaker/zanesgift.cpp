#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[200005], dp[200005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];
	
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i + 1] = max(dp[i], dp[i + 1]);
		int v = i + a[i] + 1;
		if (v <= n + 1) dp[v] = max(dp[v], dp[i] + a[i] + 1);
	}
	cout << n - dp[n + 1];
}
