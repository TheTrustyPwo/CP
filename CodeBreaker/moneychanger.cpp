#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, v; cin >> n >> v;
	int c[n]; for (int i = 0; i < n; i++) cin >> c[i];
	sort(c, c + n);
	int dp[v+1]; for (int i = 0; i <= v; i++) dp[i] = 1e9;
	dp[0] = 0;
	for (int i = 1; i <= v; i++)
		for (int j = 0; j < n; j++)
			if (i - c[j] >= 0) dp[i] = min(dp[i], dp[i - c[j]] + 1);
			else break;
	cout << (dp[v] == 1e9 ? -1 : dp[v]);
}
