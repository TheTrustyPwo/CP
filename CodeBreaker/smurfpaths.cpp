#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x, q, cnt = 1, a[500005], pos[500005], pre[500005], post[500005];
int lazy[1048576], ft[500005];
pair<int, int> t[1048576];;
vector<int> g[500005];

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = make_pair(a[pos[l]], l); return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = max(t[idx * 2], t[idx * 2 + 1]);
}

void propogate(int v) {
	t[v * 2].first += lazy[v], lazy[v * 2] += lazy[v];
    t[v * 2 + 1].first += lazy[v], lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int idx, int l, int r, int a, int b, int v) {
	if (a > b) return;
	if (l == a && r == b) {
		t[idx].first += v;
		lazy[idx] += v;
	} else {
		propogate(idx);
		int m = (l + r) / 2;
		update(idx * 2, l, m, a, min(b, m), v);
		update(idx * 2 + 1, m + 1, r, max(a, m + 1), b, v);
		t[idx] = max(t[idx * 2], t[idx * 2 + 1]);
	}
}

void add(int p, int v) {
	while (p <= n) {
		ft[p] += v;
		p += p & -p;
	}
}

int get(int p) {
	int res = 0;
	while (p) {
		res += ft[p];
		p -= p & -p;
	}
	return res;
}

int sum(int l, int r) {
	return get(r) - get(l - 1);
}

void dfs(int v, int p) {
	pos[cnt] = v;
	pre[v] = cnt++;
	for (const int u : g[v])
		if (u != p) dfs(u, v);
	post[v] = cnt - 1;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
		if (a[i] >= x) add(pre[i], 1), a[i] = -1e18;
	build(1, 1, n);

	cin >> q; while (q--) {
		int ty; cin >> ty;
		if (ty == 1) {
			int s, c; cin >> s >> c;
			update(1, 1, n, pre[s], post[s], c);
			pair<int, int> p = t[1];
			while (p.first >= x) {
				update(1, 1, n, p.second, p.second, -1e18);
				add(p.second, 1);
				p = t[1];
			}
		} else {
			int y; cin >> y;
			if (y == 1) { cout << "0\n"; continue; }
			int in = sum(pre[y], post[y]), out = sum(1, n);
			cout << in * (out - in) << "\n";
		}
	}
}
