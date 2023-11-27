#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans = 0, sz[500005]{};
bool visited[500005]{};
vector<int> g[500005];

int dfs(int u) {
	visited[u] = true;
	sz[u] = 1;
	for (const int v : g[u]) if (!visited[v]) sz[u] += dfs(v);
	ans += (sz[u] * (n - sz[u]));
	return sz[u];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(0);
	
	cout << ans * 2;
}
