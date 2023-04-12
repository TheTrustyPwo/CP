#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n], at[n], b[n], bt[n];
	int e1, e2; cin >> e1 >> e2;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	a[0] += e1; b[0] += e2;
	at[0] = 0; bt[0] = 0;
	for (int i = 1; i < n; i++) cin >> at[i];
	for (int i = 1; i < n; i++) cin >> bt[i];
	int x1, x2; cin >> x1 >> x2;
	
	int dp[n+1][2]; dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = a[i-1] + min(dp[i-1][0], dp[i-1][1] + bt[i-1]);
		dp[i][1] = b[i-1] + min(dp[i-1][1], dp[i-1][0] + at[i-1]);
	}
	
	cout << min(dp[n][0] + x1, dp[n][1] + x2);
}
