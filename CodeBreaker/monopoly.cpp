#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1000000007;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int dp[400005]; for (int i = 0; i <= 400005; i++) dp[i] = 0;
	dp[0] = 1;
	for (int i = 1; i <= 400005; i++)
		for (int j = 1; j <= 6; j++)
			if (i >= j) dp[i] = ((dp[i] % m) + (dp[i - j] % m)) % m;
	int tc; cin >> tc;
	while (tc--) {
		int n, x; char s; cin >> n >> s >> x;
		int a = n - 1;
		if (s == 'A') a = 0;
		else if (s == 'C') a *= 2;
		else if (s == 'D') a *= 3;
		a += x;
		if (a == (n - 1) * 4) a = 0;
		cout << dp[a] << endl;
	}
}
