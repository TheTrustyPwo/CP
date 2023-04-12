#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 100005, LOG = 20;

int n, q, up[MAXN][LOG], depth[MAXN], dist[MAXN];
vector<pair<int, int>> adj[MAXN];

void dfs(int v, int p, int d) {
	up[v][0] = p;
	if (v != 1) { dist[v] = dist[p] + d; depth[v] = depth[p] + 1; }
	for (int i = 1; i < LOG; i++)
		if (dist[v] < (1 << i)) up[v][i] = 0;
		else up[v][i] = up[up[v][i - 1]][i - 1];
	for (const pair<int, int> u : adj[v])
		if (u.first != p) dfs(u.first, v, u.second);
}

int kpar(int x, int k) {
	if (depth[x] < k) return 0;
	for (int i = 0; i < LOG; i++)
		if (k & (1 << i)) x = up[x][i];
	return x;
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	a = kpar(a, depth[a] - depth[b]);
	if (a == b) return a;
	for (int k = LOG - 1; k >= 0; k--)
		if (up[a][k] != up[b][k])
			a = up[a][k], b = up[b][k];
	return up[a][0];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	
	dfs(1, 1, 0);
	
	while (q--) {
		int a, b; cin >> a >> b;
		cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << "\n";
	}
}
