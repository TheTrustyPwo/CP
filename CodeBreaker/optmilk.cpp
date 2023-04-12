#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 40005;

struct val {
	int full, lft, rht, none;
};

int n, d, a[MAXN];
val t[4*MAXN];

val combine(val l, val r) {
	val v;
	v.none = max(l.rht + r.none, l.none + r.lft);
	v.lft = max(l.lft + r.lft, l.full + r.none);
	v.rht = max(r.rht + l.rht, r.full + l.none);
	v.full = max(l.lft + r.full, r.rht + l.full);
	return v;
}

val make_val(int x) {
	val v;
	v.full = x;
	v.none = v.lft = v.rht = 0;
	return v;
}

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = make_val(a[l]); return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
}

void update(int idx, int l, int r, int p, int v) {
	if (l == r) { t[idx].full = v; return; }
	int m = (l + r) / 2;
	if (p <= m) update(idx * 2, l, m, p, v);
	else update(idx * 2 + 1, m + 1, r, p, v);
	t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
}

int query() {
	return t[1].full;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	int res = 0;
	for (int i = 0; i < d; i++) {
		int x, y; cin >> x >> y;
		update(1, 1, n, x, y);
		res += query();
	}
	cout << res;
}
