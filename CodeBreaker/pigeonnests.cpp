#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 300005

int n, q;
vector<pair<int, int>> g[N];
int z = 0, pos[N], pre[N], post[N], dist[N];
pair<int, int> t[4 * N];
int lazy[4 * N];
bool used[N];

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = make_pair(dist[pos[l]], l); return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = max(t[idx * 2], t[idx * 2 + 1]);
}

void push(int v) {
	t[v * 2].first += lazy[v];
	lazy[v * 2] += lazy[v];
	t[v * 2 + 1].first += lazy[v];
	lazy[v * 2 + 1] += lazy[v];
	lazy[v] = 0;
}

void update(int idx, int l, int r, int tl, int tr, int v) {
	if (tl > tr) return;
	if (l == tl && r == tr) {
		t[idx].first += v;
		lazy[idx] += v;
	} else {
		push(idx);
		int m = (l + r) / 2;
		update(idx * 2, l, m, tl, min(tr, m), v);
		update(idx * 2 + 1, m + 1, r, max(tl, m + 1), tr, v);
		t[idx] = max(t[idx * 2], t[idx * 2 + 1]);
	}
}

pair<int, int> query(int idx, int l, int r, int tl, int tr) {
	if (tl > tr) return make_pair(-1e15, -1);
	if (l == tl && r == tr) return t[idx];
	push(idx);
	int m = (l + r) / 2;
	return max(query(idx * 2, l, m, tl, min(tr, m)),
			   query(idx * 2 + 1, m + 1, r, max(tl, m + 1), tr));
}

void dfs(int v, int p, int d) {
	pos[z] = v;
	pre[v] = z++;
	dist[v] = d;
	for (const auto u : g[v])
		if (u.first != p)
			dfs(u.first, v, d + u.second);
	post[v] = z - 1;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	
	dfs(0, 0, 0);
	build(1, 0, n - 1);
	
	while (q--) {
		int type, x; cin >> type >> x;
		if (type == 1) {
			int v = query(1, 0, n - 1, pre[x], post[x]).second;
			if (v == -1 || used[x]) {
				cout << -1 << '\n';
				continue;
			}
			cout << v << '\n';
			used[v] = 1;
			update(1, 0, n - 1, pre[v], post[v], -1e12);
		} else {
			used[x] = 0;
			update(1, 0, n - 1, pre[x], post[x], 1e12);
		}
	}
}
