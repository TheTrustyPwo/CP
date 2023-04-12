#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

int n, m, a[MAXN];
pair<int, int> t[4*MAXN];

pair<int, int> combine(pair<int, int> l, pair<int, int> r) {
	if (l.first > r.first) return l;
	else if (l.first == r.first) return (l.second < r.second ? l : r);
	else return r;
}

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = make_pair(a[l], l); return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
}

void update(int idx, int l, int r, int p, pair<int, int> v) {
	if (l == r) { t[idx] = v; return; }
	int m = (l + r) / 2;
	if (p <= m) update(idx * 2, l, m, p, v);
	else update(idx * 2 + 1, m + 1, r, p, v);
	t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
}

pair<int, int> query(int idx, int l, int r, int tl, int tr) {
	if (tl <= l && r <= tr) return t[idx];
	if (tl > r || l > tr) return make_pair(-1, -1);
	int m = (l + r) / 2;
	return combine(query(idx * 2, l, m, tl, tr), query(idx * 2 + 1, m + 1, r, tl, tr));
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n - 1);
	while (m--) {
		int a, b; cin >> a >> b;
		pair<int, int> p = query(1, 0, n - 1, a, b);
		cout << p.first << "\n";
		if (p.first != -1) update(1, 0, n - 1, p.second, make_pair(-1, -1));
	}
}
