#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005, LOG = 20;

int n, q, up[MAXN][LOG], depth[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	up[v][0] = p;
	if (v != 0) depth[v] = depth[p] + 1;
	for (int i = 1; i < LOG; i++)
		if (depth[v] >= (1 << i)) up[v][i] = up[up[v][i - 1]][i - 1];
		else up[v][i] = -1;
	for (const int u : adj[v])
		if (u != p) dfs(u, v);
	
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0, 0);
	
	cin >> q;
	while (q--) {
		int x, k; cin >> x >> k;
		if (depth[x] < k) { cout << -1 << "\n"; continue; }
		for (int i = 0; i < LOG; i++)
			if (k & (1 << i)) x = up[x][i];
		cout << x << "\n";
	}
}
