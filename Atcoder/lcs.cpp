#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string a, b; cin >> a >> b;
	int n = a.size(), m = b.size();
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
		if (i == 0 || j == 0) dp[i][j] = 0;
		else {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	string res = "";
	while(n && m) {
		if(a[n - 1] == b[m - 1]) {
			res += a[n - 1];
			n--;
			m--;
		}
		else if (dp[n - 1][m] > dp[n][m - 1]) n--;
		else m--;
	}
	
	reverse(res.begin(), res.end());
	cout << res;
}
