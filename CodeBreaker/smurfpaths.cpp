#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500005;

int n, x, q, cnt, a[MAXN], pre[MAXN], post[MAXN], lazy[4*MAXN];
pair<int, int> t[4*MAXN];;
vector<int> g[MAXN];

pair<int, int> combine(const pair<int, int> l, const pair<int, int> r) {
	if (l.first > r.first) return l;
	else return r;
}

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = make_pair(a[l], l); return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
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
		t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
	}
}

pair<int, int> query(int idx, int l, int r, int a, int b) {
	if (a > b) return make_pair(-1, -1);
	if (a <= l && r <= b) return t[idx];
	propogate(idx);
	int m = (l + r) / 2;
	return combine(query(idx * 2, l, m, a, min(b, m)), query(idx * 2 + 1, m + 1, r, max(a, m + 1), b));
}

struct FenwickTree {
    vector<int> bit;

    FenwickTree() {
		for (int i = 0; i < n; i++) add(i, a[i] >= x);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
} *fw;

void dfs(int v, int p) {
	pre[v] = cnt++;
	for (const int u : g[v])
		if (u != p) dfs(u, v);
	post[v] = cnt - 1;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1, 1);
	build(1, 0, n - 1);
	
	cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int s, c; cin >> s >> c; s--;
			update(1, 0, n - 1, pre[s], post[s], c);
			pair<int, int> p = query(1, 0, n - 1, 0, n - 1);
			while (p.first >= x) {
				a[p.second] = -1e9;
				fw -> add(p.second, 1);
			}
		} else if (t == 2) {
			int y; cin >> y; y--;
			if (y == 0) { cout << 0; continue; }
			int a = fw -> sum(n - 1), b = fw -> sum(pre[y] + 1, post[y]);
			cout << b * (a - b) << "\n";
		}
	}
}
