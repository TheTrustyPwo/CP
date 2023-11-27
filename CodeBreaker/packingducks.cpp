#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9 + 7;

int n, k;
int a[205], dp[205][50005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) {
		if (i == 0 || j == 0) dp[i][j] = 1;
		else dp[i][j] = (dp[i-1][j] + (j >= a[i] ? dp[i-1][j-a[i]] : 0)) % m;
	}
	
	for (int i = 0; i <= n; i++) { for (int j = 0; j <= k; j++) cout << dp[i][j] << ' '; cout << '\n'; }
	
	cout << dp[n][k];
}
