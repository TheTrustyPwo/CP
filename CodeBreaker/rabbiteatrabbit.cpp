#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int dp1[n+1][k+1][2];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0 || j == 0) dp1[i][j][0] = dp1[i][j][1] = 0;
			else if (i == 1) dp1[i][j][0] = dp1[i][j][1] = a[0];
			else if (i == 2) dp1[i][j][0] = a[0], dp1[i][j][1] = a[0];
			else dp1[i][j][0] = max(dp1[i-1][j][0], dp1[i-1][j][1]), dp1[i][j][1] = a[i-1] + dp1[i-1][j-1][0];
		}
	}
	
	int a1 = dp1[n][k][0];
	
	int dp2[n+1][k+1][2];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0 || j == 0) dp2[i][j][0] = dp2[i][j][1] = 0;
			else if (i == 1) dp2[i][j][0] = dp2[i][j][1] = 0;
			else dp2[i][j][0] = max(dp2[i-1][j][0], dp2[i-1][j][1]), dp2[i][j][1] = a[i-1] + dp2[i-1][j-1][0];
		}
	}
	
	int a2 = max(dp2[n][k][0], dp2[n][k][1]);
	
	cout << max(a1, a2);
}
