#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005, LOG = 20;

vector<int> adj[MAXN];
int n, q, up[MAXN][LOG], depth[MAXN];

void dfs(int v, int p) {
	up[v][0] = p;
	if (v != 0) depth[v] = depth[p] + 1;
	for (int i = 1; i < LOG; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (const int u : adj[v])
		if (u != p) dfs(u, v);
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

int dist (int u, int v) {
    int x = lca(u, v);
    int res = depth[u] + depth[v] - 2 * depth[x];
    return res;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);

    pair<int, int> p[6];
    while (q--) {
        int u, v, r; cin >> r >> u >> v;

        p[0].second = u;
        p[1].second = v;
        p[2].second = r;
        p[3].second = lca(r, u);
        p[4].second = lca(r, v);
        p[5].second = lca(u, v);

        for (int i = 0; i < 6; i++) {
            int x = p[i].second;
            p[i].first = dist(x, r) + dist(x, u) + dist(x, v);
        }

        sort(p, p + 6);

        cout << p[0].second << endl;
    }
}
