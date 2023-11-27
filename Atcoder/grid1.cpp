#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int h, w; cin >> h >> w;
	bool g[h + 1][w + 1];
	for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) {
		char ch; cin >> ch;
		g[i][j] = ch == '#';
	}
	
	int dp[h + 1][w + 1];
	for (int i = 0; i <= h; i++) for (int j = 0; j <= w; j++) dp[i][j] = 0;
	dp[1][1] = 1;
	for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) {
		if (g[i][j]) { dp[i][j] = 0; continue; }
		if (i > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % m;
		if (j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % m;
	}
	
	cout << dp[h][w];
}
