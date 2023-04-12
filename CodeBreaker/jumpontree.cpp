#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500005, LOG = 22;

int n, q, up[MAXN][LOG], depth[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	up[v][0] = p;
	if (v != 0) depth[v] = depth[p] + 1;
	for (int i = 1; i < LOG; i++)
		if (depth[v] < (1 << i)) up[v][i] = -1;
		else up[v][i] = up[up[v][i - 1]][i - 1];
	for (const int u : adj[v])
		if (u != p) dfs(u, v);
}

int kpar(int x, int k) {
	if (depth[x] < k) return -1;
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
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(0, 0);
	
	while (q--) {
		int s, t, i; cin >> s >> t >> i;
		int l = lca(s, t);
		int d = depth[s] + depth[t] - 2 * depth[l];
		if (i > d) cout << -1;
		else if (i < depth[s] - depth[l]) cout << kpar(s, i);
		else cout << kpar(t, d - i);
		cout << "\n";
	}
}
