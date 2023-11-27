#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int dp[100005];
vector<int> g[100005];

int dfs(int v) {
	if (dp[v] != 0) return dp[v];
	for (const int &u : g[v]) {
		dp[u] = dfs(u);
		dp[v] = max(dp[v], dp[u] + 1);
	}
	return dp[v];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}
	
	fill(dp, dp + n, 0);
	
	for (int i = 0; i < n; i++) dfs(i);
	
	cout << *max_element(dp, dp + n);
}
