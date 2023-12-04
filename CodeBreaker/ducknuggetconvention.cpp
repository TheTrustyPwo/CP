#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update
> st_t;

int n, q, c[200005];
st_t t[524288];

void build(int idx, int l, int r) {
	if (l == r) { st_t st; st.insert(c[l]); t[idx] = st; return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	st_t st;
	for (auto &i : t[idx * 2]) st.insert(i);
	for (auto &i : t[idx * 2 + 1]) st.insert(i);
	t[idx] = st;
}

int query(int idx, int l, int r, int tl, int tr, int x) {
	if (tl > tr) return 0;
	if (l == tl && r == tr) {
		return t[idx].order_of_key(x + 1);
	}
	int m = (l + r) / 2;
	return query(idx * 2, l, m, tl, min(r, m), x) +
				query(idx * 2 + 1, m + 1, r, max(tl, m + 1), tr, x);
}

void update(int idx, int l, int r, int p, int v) {
	t[idx].erase(t[idx].find(c[p]));
	t[idx].insert(v);
	if (l == r) c[p] = v;
	else {
		int m = (l + r) / 2;
		if (p <= m) update(idx * 2, l, m, p, v);
		else update(idx * 2 + 1, m + 1, r, p, v);
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> c[i];
	build(1, 1, n);
	int type, l, r, k;
	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> l >> r >> k;
			cout << query(1, 1, n, l, r, k) << '\n';
		} else {
			cin >> r >> k;
			update(1, 1, n, r, k);
		}
	}
}
