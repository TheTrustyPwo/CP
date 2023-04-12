#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 100005;

int n, m;
string a[MAXN], lazy[4*MAXN], t[4*MAXN];

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = a[l]; return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = t[idx * 2] + t[idx * 2 + 1];
}

void propogate(int v) {
	t[v * 2] = lazy[v], lazy[v * 2] = lazy[v];
    t[v * 2 + 1] = lazy[v], lazy[v * 2 + 1] = lazy[v];
    lazy[v] = "0";
}

void update(int idx, int l, int r, int a, int b, string v) {
	if (a > b) return;
	if (l == a && r == b) {
		t[idx] += v;
		lazy[idx] += v;
	} else {
		propogate(idx);
		int m = (l + r) / 2;
		update(idx * 2, l, m, a, min(b, m), v);
		update(idx * 2 + 1, m + 1, r, max(a, m + 1), b, v);
		t[idx] = t[idx * 2] + t[idx * 2 + 1];
	}
}

string query(int idx, int l, int r, int a, int b) {
	if (a > b) return "";
	if (a <= l && r <= b) return t[idx];
	propogate(idx);
	int m = (l + r) / 2;
	return query(idx * 2, l, m, a, min(b, m)) + query(idx * 2 + 1, m + 1, r, max(a, m + 1), b);
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) a[i] = "1";
	build(1, 1, n);
	while (m--) {
		int a, b; string s; cin >> a >> b >> s;
		update(1, 1, n, a, b, s);
		cout << query(1, 1, n, 1, n) << '\n';
	}
}
