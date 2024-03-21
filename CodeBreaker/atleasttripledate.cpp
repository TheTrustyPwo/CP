#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 1e9 + 7;

int dp[2005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	dp[0] = 1; dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		for (int j = 0; j <= i - 3; j++) dp[i] = (dp[i] + dp[j]) % m;
	}
	cout << dp[n];
}
