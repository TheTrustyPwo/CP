#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 13371337;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a; cin >> n >> a;
	int c[n]; for (int i = 0; i < n; i++) cin >> c[i];
	int dp[a+1]; for (int i = 1; i <= a; i++) dp[i] = 0;
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = c[i]; j <= a; j++)
			dp[j] = ((dp[j] % m) + (dp[j - c[i]] % m)) % m;
	cout << dp[a];
}
