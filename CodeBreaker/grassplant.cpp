#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

int n, q, parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], cur = 1;
ll fw[MAXN], fw2[MAXN];
vector<int> g[MAXN];

void update(ll x, ll y, ll v) {
	for (ll tx = x; tx <= n; tx += tx & (-tx)) fw[tx] += v, fw2[tx] -= v * (x - 1);
	for (ll ty = y + 1; ty <= n; ty += ty & (-ty)) fw[ty] -= v, fw2[ty] += v * y;
}

ll sum(ll x) {
	ll res = 0;
	for (ll tx = x; tx; tx -= tx & (-tx)) res += fw[tx] * x + fw2[tx];
	return res;
}

ll range_sum(ll x, ll y) {
	return sum(y) - sum(x - 1);
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
	head[v] = h, pos[v] = cur++;
	if (heavy[v] != -1) decompose(heavy[v], h);
	for (const int u : g[v])
		if (u != parent[v] && u != heavy[v])
			decompose(u, u);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	memset(heavy, -1, sizeof(heavy));
	dfs(1);
	decompose(1, 1);
	
	while (q--) {
		char c; int a, b; cin >> c >> a >> b;
		if (c == 'P') {
			if (depth[a] > depth[b]) swap(a, b);
			for (; head[a] != head[b]; b = parent[head[b]]) {
				if (depth[head[a]] > depth[head[b]]) swap(a, b);
				update(pos[head[b]], pos[b], 1);
			}
			if (depth[a] > depth[b]) swap(a, b);
			update(pos[a] + 1, pos[b], 1);
		} else {
			int res = 0;
			if (depth[a] > depth[b]) swap(a, b);
			for (; head[a] != head[b]; b = parent[head[b]]) {
				if (depth[head[a]] > depth[head[b]]) swap(a, b);
				res += range_sum(pos[head[b]], pos[b]);
			}
			if (depth[a] > depth[b]) swap(a, b);
			res += range_sum(pos[a] + 1, pos[b]);
			cout << res << "\n";
		}
	}
}
