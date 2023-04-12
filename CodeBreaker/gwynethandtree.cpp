#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

int n, q, parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], hsize[MAXN], cur = 1;
int ftl[MAXN], ftr[MAXN];
vector<int> g[MAXN];

void update(int p, int v, int* ft, int m) {
	for (; p <= m; v += (p & -p), p += (p & -p)) ft[p] = min(ft[p], v);
}

int query(int p, int* ft) {
	int res = n, k = 0;
	for (; p; k += (p & -p), p -= (p & -p)) res = min(res, ft[p] + k);
	return res;
}

int dfs(int v) {
	int size = 1, mchild = 0;
	for (const int u : g[v]) {
		if (u == parent[v]) continue;
		parent[u] = v, depth[u] = depth[v] + 1;
		int csize = dfs(u);
		size += csize;
		if (csize > mchild) mchild = csize, heavy[v] = u;
	}
	return size;
}

void decompose(int v, int h) {
	head[v] = h, hsize[h]++, pos[v] = cur++;
	if (heavy[v] != -1) decompose(heavy[v], h);
	for (const int u : g[v])
		if (u != parent[v] && u != heavy[v])
			decompose(u, u);
}

int chainpos(int v) {
	return pos[v] - pos[head[v]] + 1;
}

void changecolor(int v, int k) {
	int h = head[v], p = parent[h];
	update(chainpos(v), k, ftl + pos[h] - 1, hsize[h]);
	update(hsize[h] - chainpos(v) + 1, k, ftr + pos[h] - 1, hsize[h]);
	if (!p) return;
	changecolor(p, query(hsize[h], ftr + pos[h] - 1) + 1);
}

int dist(int v) {
	if (!v) return n;
	int d = min(query(chainpos(v), ftl + pos[head[v]] - 1), query(hsize[head[v]] - chainpos(v) + 1, ftr + pos[head[v]] - 1));
	return min(d, dist(parent[head[v]]) + 1 + pos[v] - pos[head[v]]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	for (int i = 0; i <= n; i++) ftl[i] = ftr[i] = n;
	
	memset(heavy, -1, sizeof(heavy));
	dfs(1);
	decompose(1, 1);
	changecolor(1, 0);
	
	while (q--) {
		int a, b; cin >> a >> b;
		if (a == 1) changecolor(b, 0);
		else cout << dist(b) << "\n";
	}
}
