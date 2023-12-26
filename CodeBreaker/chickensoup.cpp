#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 998244353;

int n, q, a[200005], pre[200005];

int fw1[200005], fw2[200005], fw3[200005];

void update(int *t, int p, int v) {
	while (p <= n) {
		t[p] = (t[p] + v + M) % M;
		p += p & -p;
	}
}

int query(int *t, int p) {
	int res = 0;
	while (p) {
		res = (res + t[p]) % M;
		p -= p & -p;
	}
	return res;
}

int query(int *t, int l, int r) {
	return (query(t, r) - query(t, l - 1) + M) % M;
}

int calc(int x) {
	x = n - x + 1;
	return ((x * (x + 1)) / 2) % M;
}

int calc2(int x) {
	return 2 * (n - x + 1);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(fw1, i, a[i]);
		update(fw2, i, (calc2(i) * a[i]) % M);
		update(fw3, i, (calc(i) * a[i]) % M);
	}
	
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int x, v; cin >> x >> v; v %= M;
			int tmp = (v - a[x] + M) % M;
			update(fw1, x, tmp);
			update(fw2, x, (calc2(x) * tmp) % M);
			update(fw3, x, (calc(x) * tmp) % M);
			a[x] = v;
		} else {
			int x; cin >> x;
			int tmp = 2 * n - (n + x + 1);
			int res = query(fw3, 1, x);
			int consecutive = query(fw2, 1, x);
			int offset = (query(fw1, 1, x) * tmp) % M;
			int tmp2 = (((consecutive - offset + M) % M) * (n - x)) % M;
			tmp2 = (tmp2 * 499122177) % M;
			res = (res - tmp2 + M) % M;
			cout << res << '\n';
		}
	}
}
