#include <bits/stdc++.h>
using namespace std;

int n, q, a, b, c, t[262144];
	
void update(int p, int v) {
	for (t[p += n] = v; p > 1; p >>= 1) t[p >> 1] = min(t[p], t[p ^ 1]);
}
	
int query(int l, int r) {
	int res = 1e9;
	for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = min(res, t[l++]);
		if (r & 1) res = min(res, t[--r]);
	}
	return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	while (q--) {
		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(b, c) << "\n";
	}
}
