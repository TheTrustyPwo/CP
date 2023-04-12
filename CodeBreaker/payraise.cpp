#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1000005;

int n, q, s[MAXN], pos[MAXN], pre[MAXN], post[MAXN], t[4 * MAXN], timer = 0;
vector<int> g[MAXN];

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = s[pos[l]]; return; }
	int m = (l + r) >> 1;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = 0;
}

void update(int idx, int l, int r, int a, int b, int x) {
	if (a > b) return;
	if (l == a && r == b) { t[idx] += x; return; }
	int m = (l + r) >> 1;
	update(idx * 2, l, m, a, min(b, m), x);
	update(idx * 2 + 1, m + 1, r, max(m + 1, a), b, x);
}

int query(int idx, int l, int r, int p) {
	if (l == r) return t[idx];
	int m = (l + r) >> 1;
	if (p <= m) return t[idx] + query(idx * 2, l, m, p);
	else return t[idx] + query(idx * 2 + 1, m + 1, r, p);
}

void dfs(int v) {
	pos[timer] = v;
	pre[v] = timer++;
	for (const int u : g[v]) dfs(u);
	post[v] = timer - 1;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x != -1) g[x].push_back(i);
	}
	
	for (int i = 0; i < n; i++) cin >> s[i];
	dfs(0);
	build(1, 0, n - 1);
	
	while (q--) {
		int t, x, d; cin >> t;
		if (t == 0) {
			cin >> x >> d;
			update(1, 0, n - 1, pre[x], post[x], d);
		} else {
			cin >> x;
			cout << query(1, 0, n - 1, pre[x]) << '\n';
		}
	}
}
