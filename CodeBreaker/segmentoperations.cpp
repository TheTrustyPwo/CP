#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<array<int, 2>, 2> matrix;
const int M = 998244353, MAXN = 300005;
const matrix ZERO = {array<int, 2>({3, 0}), array<int, 2>({1, 2})}, ONE = {array<int, 2>({1, 2}), array<int, 2>({1, 2})};

matrix operator* (const matrix &a, const matrix &b) {
	matrix c;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			c[i][j] = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				c[i][k] = (1ll * a[i][j] * b[j][k] + c[i][k]) % M;
	return c;
}

int n;
matrix t[4*MAXN];

void build(int idx, int l, int r) {
	if (l == r - 1) { t[idx] = ZERO; return; }
	int m = (l + r) >> 1;
	build(idx * 2 + 1, l, m);
	build(idx * 2 + 2, m, r);
	t[idx] = t[idx * 2 + 1] * t[idx * 2 + 2];
}

void update(int idx, int l, int r, int p, int v) {
	if (l == r - 1) { t[idx] = (v == 0 ? ZERO : ONE); return; }
	int m = (l + r) >> 1;
	if (p < m) update(idx * 2 + 1, l, m, p, v);
	else update(idx * 2 + 2, m, r, p, v);
	t[idx] = t[idx * 2 + 1] * t[idx * 2 + 2];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<vector<pair<int, int>>> v(MAXN);
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		v[l].push_back(make_pair(1, i));
		v[r + 1].push_back(make_pair(0, i));
	}
	
	build(0, 0, n - 1);
	int cur = 0, ans = 0;
	for (int i = 0; i <= 300000; i++) {
		for (const auto x : v[i]) {
			if (x.second == 0) cur = x.first;
			else update(0, 0, n - 1, x.second - 1, x.first);
		}
		ans = (ans + t[0][cur][1]) % M;
	}
	
	cout << ans;
}
