#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, s, q, a[250005], t[524288];
vector<pair<int, int>> pending;
set<pair<int, int>, greater<pair<int, int>>> st;

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = a[l]; return; }
	int m = (l + r) >> 1;
	build(idx << 1, l, m);
	build(idx << 1 | 1, m + 1, r);
	t[idx] = max(t[idx << 1], t[idx << 1 | 1]);
}

void update(int idx, int l, int r, int p, int v) {
	if (l > r) return;
	if (l == r) { t[idx] = v; return; }
	int m = (l + r) >> 1;
	if (p <= m) update(idx << 1, l, m, p, v);
	else update(idx << 1 | 1, m + 1, r, p, v);
	t[idx] = max(t[idx << 1], t[idx << 1 | 1]);
}

int query(int idx, int l, int r, int tl, int tr) {
	if (tl > tr) return 0;
	if (l == tl && r == tr) return t[idx];
	int m = (l + r) >> 1;
	return max(query(idx << 1, l, m, tl, min(m, tr)), query(idx << 1 | 1, m + 1, r, max(m + 1, tl), tr));
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (n - a[i] <= 10) st.insert(make_pair(a[i], i));
	}
	
	build(1, 1, n);
	
	cin >> q; char t; int x, y;
	while (q--) {
		cin >> t;
		if (t == 'F') {
			cin >> x;
			if (x == s) cout << 0 << '\n';
			else if (x < s) {
				int mx = query(1, 1, n, x, s - 1);
				int l = s + 1, r = n, ans = n + 1;
				while (l <= r) {
					int m = (l + r) >> 1;
					if (query(1, 1, n, s + 1, m) > mx) {
						ans = m;
						r = m - 1;
					} else l = m + 1;
				}
				cout << (ans - x - 1) << '\n';
			} else {
				int mx = query(1, 1, n, s + 1, x);
				int l = 1, r = s - 1, ans = 0;
				while (l <= r) {
					int m = (l + r) >> 1;
					if (query(1, 1, n, m, r) > mx) {
						ans = m;
						l = m + 1;
					} else r = m - 1;
				}
				cout << (x - ans - 1) << '\n';
			}
		} else {
			cin >> x >> y;
			int pos = 1, res = -1; pending.clear();
			for (auto it = st.begin(); it != st.end() && pos <= y;) {
				pair<int, int> p = *it;
				if (pos == y) { res = p.first; break; }
				it = st.erase(it);
				pending.push_back(make_pair(p.first + 1, p.second));
				update(1, 1, n, p.second, p.first + 1);
				a[p.second] = p.first + 1;
				pos++;
			}
			
			for (const auto &p : pending) st.insert(p);
			
			auto it = st.lower_bound(make_pair(a[x], 1e9));
			if (it != st.end()) st.erase(it);
			st.insert(make_pair(res + 1, x));
			update(1, 1, n, x, res + 1); a[x] = res + 1;
			if (st.size() > 10) st.erase(--st.end());
			
			// for (auto it = st.begin(); it != st.end(); it++) cout << (*it).first << ' ' << (*it).second << '\n';
		}
	}
}
