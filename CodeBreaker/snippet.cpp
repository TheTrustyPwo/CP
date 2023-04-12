#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;

int n, q, h;
int h = sizeof(int) * 8 - __builtin_clz(n);

struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
	
__gnu_pbds::gp_hash_table<int, int, chash> t, z;

void apply(int p, int v, int k) {
	t[p] += v * k, z[p] += (p < n) * v;
}

void propogate(int p) {
	for (int s = h; s; s--;) {
		int i = p >> s;
		if (!z[i]) continue;
		apply(i << 1, z[i]);
		apply(i << 1 | 1, z[i]);
		z[i] = 0;
	}
}
	
void update(int l, int r, int val) {
	l += n, r += n + 1, l1 = l, r1 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) apply(l++, v);
		if (r & 1) apply(--r, v);
	}
	
}

int query(int l, int r) {
	int res = 0; l += n, r += n + 1, push(l), push(r - 1);
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
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(b, c) << "\n";
	}
}
