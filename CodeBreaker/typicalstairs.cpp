#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

int n, m, x, dp[100005] = {0, 1};
bool h[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		h[x] = 1;
	}
	
	for (int i = 2; i <= n + 1; i++) {
		if (h[i - 1]) dp[i] = 0;
		else dp[i] = (dp[i - 1] + dp[i - 2]) % M;
	}
	
	cout << dp[n + 1];
}
