#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005, M = 998244353;
 
int n, q, t[MAXN << 2], m[MAXN << 2], a[MAXN << 2];
 
 
int add(int a, int b) {
    int c = a + b;
    if (c >= M) c -= M;
    return c;
}

int mul(int a, int b) {
    int c = 1ll * a * b;
    if (c >= M) c %= M;
    return c;
}

 
void propogate(int v, int l, int r) {
	if(m[v] > 1) {
		t[v] = mul(t[v], m[v]);
		if(l ^ r) {
			m[v * 2] = mul(m[v * 2], m[v]);
			a[v * 2] = mul(a[v * 2], m[v]);
			m[v * 2 + 1] = mul(m[v * 2 + 1], m[v]);
			a[v * 2 + 1] = mul(a[v * 2 + 1], m[v]);
		}
		m[v] = 1;
	}
	
	if(a[v] > 0) {
		t[v] = add(t[v], mul(r - l + 1, a[v]));
		if(l ^ r) {
			a[v * 2] = add(a[v * 2], a[v]);
			a[v * 2 + 1] = add(a[v * 2 + 1], a[v]);
		}
		a[v] = 0;
	}
}
 
void update(int v, int l, int r, int L, int R, int mx, int ax) {
	propogate(v, l, r);
	if(l > R || r < L) return;
	if(l >= L && r <= R) {
		m[v] = mx, a[v] = ax;
		propogate(v, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	update(v * 2, l, mid, L, R, mx, ax);
	update(v * 2 + 1, mid + 1, r, L, R, mx, ax);
	t[v] = add(t[v * 2], t[v * 2 + 1]);
}
 
int query(int v, int l, int r, int L, int R) {
	propogate(v, l, r);
	if(l > R || r < L) return 0;
	if(l >= L && r <= R) return t[v];
	int mid = (l + r) >> 1;
	return add(query(v * 2, l, mid, L, R), query(v * 2 + 1, mid + 1, r, L, R));
}
 
 
set<pair<int, int>> st[MAXN];
 
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	fill(m, m + (MAXN << 2), 1);
	
	while (q--) {
		int type, l, r, x; cin >> type >> l >> r;
		if (type == 1) {
			cin >> x;
			int lx = l, rx = r, prv = l;
			vector<pair<int, int>> v;
			for(auto it = st[x].lower_bound(make_pair(l, -1)); it != st[x].end(); ++it) {
				if(it -> second > r) break;
				v.push_back(*it);
				rx = max(rx, it -> first);
				lx = min(lx, it -> second);
				if(prv < it -> second) update(1, 1, n, prv, it -> second - 1, 1, 1);
				update(1, 1, n, max(prv, it -> second), min(r, it -> first), 2, 0);
				prv = it -> first + 1;
			}
			if(prv <= r) update(1, 1, n, prv, r, 1, 1);
			for (auto y : v) st[x].erase(y);
			st[x].insert(make_pair(rx, lx));
		} else {
			cout << query(1, 1, n, l, r) << "\n";
		}
	}
}
