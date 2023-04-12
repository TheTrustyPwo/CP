#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 100005;

int n, m, a[MAXN], lazy[4*MAXN], t[4*MAXN];

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = a[l]; return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = max(t[idx * 2], t[idx * 2 + 1]);
}

void propogate(int v) {
	t[v * 2] += lazy[v], lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v], lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int idx, int l, int r, int a, int b, int v) {
	if (a > b) return;
	if (l == a && r == b) {
		t[idx] += v;
		lazy[idx] += v;
	} else {
		propogate(idx);
		int m = (l + r) / 2;
		update(idx * 2, l, m, a, min(b, m), v);
		update(idx * 2 + 1, m + 1, r, max(a, m + 1), b, v);
		t[idx] = max(t[idx * 2], t[idx * 2 + 1]);
	}
}

int query(int idx, int l, int r, int a, int b) {
	if (a > b) return -1e18;
	if (a <= l && r <= b) return t[idx];
	propogate(idx);
	int m = (l + r) / 2;
	return max(query(idx * 2, l, m, a, min(b, m)), query(idx * 2 + 1, m + 1, r, max(a, m + 1), b));
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n - 1);
	cin >> m;
	while (m--) {
		bool q; int a, b, c; cin >> q;
		if (q) {
			cin >> a >> b >> c;
			update(1, 0, n - 1, a, b, c);
		} else {
			cin >> a >> b;
			cout << query(1, 0, n - 1, a, b) << "\n";
		}
		for (int i = 0; i <= 32; i++) cout << t[i] << ' ';
		cout << '\n';
	}
}
