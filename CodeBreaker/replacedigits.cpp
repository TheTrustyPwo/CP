#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 998244353;

int n, q, tens[200005];
int t[524288], lazy[524288], s[524288];

void build(int idx, int l, int r) {
	lazy[idx] = 0;
	if (l == r) { t[idx] = s[idx] = tens[l]; return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = (t[idx * 2] + t[idx * 2 + 1]) % M;
	s[idx] = (s[idx * 2] + s[idx * 2 + 1]) % M;
}

void push(int idx) {
	if (lazy[idx]) {
		lazy[idx * 2] = lazy[idx * 2 + 1] = lazy[idx];
		t[idx * 2] = (lazy[idx] * s[idx * 2]) % M;
		t[idx * 2 + 1] = (lazy[idx] * s[idx * 2 + 1]) % M;
		lazy[idx] = 0;
	}
}

void update(int idx, int l, int r, int tl, int tr, int v) {
	if (tl <= l && r <= tr) {
		t[idx] = (s[idx] * v) % M;
		lazy[idx] = v;
		return;
	}
	push(idx);
	int m = (l + r) / 2;
	if (tl <= m) update(idx * 2, l, m, tl, tr, v);
	if (tr > m) update(idx * 2 + 1, m + 1, r, tl, tr, v);
	t[idx] = (t[idx * 2] + t[idx * 2 + 1]) % M;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	tens[n] = 1; for (int i = n - 1; i >= 1; i--) tens[i] = (tens[i + 1] * 10) % M;
	
	build(1, 1, n);
	while (q--) {
		int a, b, v; cin >> a >> b >> v;
		update(1, 1, n, a, b, v);
		cout << t[1] << '\n';
	}
}
