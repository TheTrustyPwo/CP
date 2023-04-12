#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;

struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};

int n, q, a, b, c, k;
__gnu_pbds::gp_hash_table<int, int, chash> t, d;

void apply(int p, int v) {
	t[p] += v;
	if (p < n) d[p] += v;
}

void build(int p) {
	while (p > 1) p >>= 1, t[p] = t[p << 1] + t[p << 1 | 1] + d[p];
}

void push(int p) {
	for (int s = n; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
			apply(i << 1, d[i]);
			apply(i << 1 | 1, d[i]);
			d[i] = 0;
		}
	}
}

void inc(int l, int r, int v) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) apply(l++, v);
		if (r & 1) apply(--r, v);
	}
	build(l0);
	build(r0 - 1);
}
	
int query(int l, int r) {
	l += n, r += n;
	push(l);
	push(r - 1);
	int res = 0;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	while (q--) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> k; b -= 2; c--;
			// cout << b << ' ' << c << ' ';
			inc(b, c, k);
		} else {
			cin >> b >> c; b -= 2; c--;
			cout << query(b, c) << "\n";
		}
		// for (int i = 1; i <= 32; i++) cout << t[i] << ' ';
		// cout << '\n';
	}
}
