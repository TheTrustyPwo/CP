#include <bits/stdc++.h>
#include "square.h"
using namespace std;
typedef long long ll;

int dp[1005][1005];

int findMaxSquare(int g[1000][1000], int n) {
	for (int i = 0; i < 1000; i++) for (int j = 0; j < 1000; j++) {
		if (!g[i][j]) continue;
		dp[i][j] = 1 + min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
	}
	
	return dp[n-1][n-1];
}
