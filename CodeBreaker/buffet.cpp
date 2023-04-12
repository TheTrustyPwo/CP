#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int p, k; cin >> p >> k;
	int a[p]; for (int i = 0; i < p; i++) cin >> a[i];
	int b[p]; for (int i = 0; i < p; i++) cin >> b[i];
	ll dp[p+1][2]; dp[0][0] = 0; dp[0][1] = 0;
	for (int i = 1; i <= p; i++) {
		dp[i][0] = a[i-1] + max(dp[i-1][0], dp[i-1][1] - k);
		dp[i][1] = b[i-1] + max(dp[i-1][1], dp[i-1][0] - k);
	}
	cout << max(dp[p][0], dp[p][1]);
}
