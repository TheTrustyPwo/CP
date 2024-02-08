#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 1e9 + 7;

struct dat {
	pair<int, int> mn, mx; int cnt;
	dat() : mn(1e9, -1), mx(-1e9, -1), cnt(0) {};
	dat(int i, int v) : mn(v, i), mx(v, i), cnt(1) {};
};

int n, k, a[300005], fac[300005], inv_fac[300005];
dat t[1048576];

dat combine(const dat d1, const dat d2) {
	dat tmp;
	tmp.mn = min(d1.mn, d2.mn);
	tmp.mx = max(d1.mx, d2.mx);
	tmp.cnt = d1.cnt + d2.cnt;
	return tmp;
}

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = dat(l, a[l]); return; }
	int m = (l + r) >> 1;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
}

dat query(int idx, int l, int r, int tl, int tr) {
	if (tl > tr) return dat();
	if (l == tl && r == tr) return t[idx];
	int m = (l + r) >> 1;
	return combine(query(idx * 2, l, m, tl, min(tr, m)), query(idx * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void del(int idx, int l, int r, int p) {
	if (l == r) { t[idx] = dat(); return; }
	int m = (l + r) >> 1;
	if (p <= m) del(idx * 2, l, m, p);
	else del(idx * 2 + 1, m + 1, r, p);
	t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
}

int exp_mod(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = r * a % m;
		a = a * a % m;
		b /= 2;
	} return r;
}

int nck(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fac[n] * inv_fac[k] % m * inv_fac[n - k] % m;
}

int solve(int l, int r) {
	dat res = query(1, 1, n, l, r);
	if (res.cnt == 0) return 1;
	if (res.mx.first + res.mn.first > k) {
		return solve(l, res.mx.second - 1) * solve(res.mx.second + 1, r) % m;
	} else {
		int freq = 0, orig = res.mn.first;
		while (res.mn.first == orig) {
			del(1, 1, n, res.mn.second);
			freq++;
			res = query(1, 1, n, l, r);
		}
		return solve(l, r) * nck(res.cnt + freq, freq) % m;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k; fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		fac[i] = fac[i - 1] * i % m;
	}
	inv_fac[n] = exp_mod(fac[n], m - 2);
	for (int i = n - 1; i >= 0; i--) inv_fac[i] = inv_fac[i + 1] * (i + 1) % m;
	build(1, 1, n);
	cout << solve(1, n);
}
