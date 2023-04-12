#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int dp[n+1]; dp[0] = 0; for (int i = 1; i <= n; i++) dp[i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if ((a[i-1] & a[j-1]) == 0)
				dp[i] = max(dp[i], dp[j] + 1);
	cout << *max_element(dp, dp + n + 1);
}
