#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[500005], b[500005], dp[500005][2];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	for (int i = 0; i <= n; i++) {
		if (i == 0) dp[i][0] = dp[i][1] = 0;
		dp[i][0] = a[i - 1] + min(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = b[i - 1]
	}
}
