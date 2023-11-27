#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, dp[105];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n; dp[0] = 1;
	for (int i = 5; i <= n; i++) for (int j = i; j <= n; j++) {
		dp[j] += dp[j - i];
	}
	cout << dp[n];
}
