#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[19][(1 << 19)], g[19][19];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int mnbit = __builtin_ctz(mask);
        if ((1 << mnbit) == mask) {
            dp[mnbit][mask] = 1;
            continue;
        }
        
		for (int i = mnbit + 1; i < n; i++) {
			if (!(mask & (1 << i))) continue;
			if (__builtin_popcount(mask) == 2) {
				dp[i][mask] = g[mnbit][i];
				continue;
			}
			for (int j = mnbit + 1; j < n; j++) 
				if (g[i][j]) dp[i][mask] += dp[j][mask ^ (1 << i)];
			ans += g[i][mnbit] * dp[i][mask];
		}
    }
    
    cout << ans / 2;
}
