#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int dp[105];
	for (int i = 0; i <= 100; i++) dp[i] = 1;
	for (int i = 10; i <= 100; i++)
		for (int j = 5; j <= (i / 2); j++)
			if (j == i - j) dp[i] += dp[j];
			else dp[i] += (dp[j] * dp[i - j]);
	cout << dp[n];
}
