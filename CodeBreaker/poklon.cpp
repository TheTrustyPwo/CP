#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, ft[500005], pv[500005], ppv[500005], ans[500005];
pair<pair<int, int>, int> queries[500005];
map<int, int> mp;

void update(int p, int v) {
	p++;
	while (p <= n) {
		ft[p] += v;
		p += p & -p;
	}
}

int query(int p) {
	p++; int res = 0;
	while (p) {
		res += ft[p];
		p -= p & -p;
	} return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (mp.find(x) == mp.end()) {
			pv[i] = ppv[i] = -1;
		} else {
			pv[i] = mp[x];
			ppv[i] = pv[pv[i]];
		}
		mp[x] = i;
	}
	
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		queries[i].first.first = --r, queries[i].first.second = --l;
		queries[i].second = i;
	}
	
	sort(queries, queries + q);

	int pr = -1;
	for (int i = 0; i < q; i++) {
		int l = queries[i].first.second, r = queries[i].first.first, id = queries[i].second;
		for (int i = pr + 1; i <= r; i++) {
			if (pv[i] != -1) update(pv[i], 1); // second nearest set to 1
			if (ppv[i] != -1) update(ppv[i], -2); // third nearest change to -1 to cancel second
			if (ppv[i] != -1 && pv[ppv[i]] != -1) update(pv[ppv[i]], 1); // change all others to 0
		}
		pr = r; ans[id] = query(r) - query(l - 1);
	}
	
	for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
