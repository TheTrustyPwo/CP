#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q, k, b[100005];
int t[262144];

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = b[l]; return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = t[idx * 2] + t[idx * 2 + 1];
}

void spray(int idx, int l, int r, int tl, int tr) {
	if (r < tl || l > tr) return;
	if (tl <= l && r <= tr) {
		if (t[idx] == 0) return;
		if (l == r) { t[idx] /= k; return; }
	}
	int m = (l + r) / 2;
	spray(idx * 2, l, m, tl, tr);
	spray(idx * 2 + 1, m + 1, r, tl, tr);
	t[idx] = t[idx * 2] + t[idx * 2 + 1];
}

void update(int idx, int l, int r, int p, int v) {
	if (p < l || p > r) return;
	if (l == r) t[idx] = v;
	else {
		int m = (l + r) / 2;
		update(idx * 2, l, m, p, v);
		update(idx * 2 + 1, m + 1, r, p, v);
		t[idx] = t[idx * 2] + t[idx * 2 + 1];
	}
}

int query(int idx, int l, int r, int tl, int tr) {
	if (r < tl || l > tr) return 0;
	if (tl <= l && r <= tr) return t[idx];
	int m = (l + r) / 2;
	return query(idx * 2, l, m, tl, tr) + query(idx * 2 + 1, m + 1, r, tl, tr);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q >> k;
	for (int i = 1; i <= n; i++) cin >> b[i];
	build(1, 1, n);
	
	while (q--) {
		int type, l, r; cin >> type >> l >> r;
		if (type == 2) {
			if (k > 1) spray(1, 1, n, l, r);
		} else if (type == 1) {
			update(1, 1, n, l, r);
		} else {
			cout << query(1, 1, n, l, r) << '\n';
		}
	}
}
