#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, d, a[100005], dp[100005], p[100005];
pair<int, int> t[1048576];

void update(int idx, int l, int r, int p, pair<int, int> v) {
	if (l == r) { t[idx] = v; return; }
	int m = (l + r) / 2;
	if (p <= m) update(idx * 2, l, m, p, v);
	else update(idx * 2 + 1, m + 1, r, p, v);
	t[idx] = max(t[idx * 2], t[idx * 2 + 1]);
}

pair<int, int> query(int idx, int l, int r, int tl, int tr) {
	if (tl > tr) return make_pair(0, 0);
	if (l == tl && r == tr) return t[idx];
	int m = (l + r) / 2;
	return max(query(idx * 2, l, m, tl, min(tr, m)), query(idx * 2 + 1, m + 1, r, max(tl, m + 1), tr));
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> d; vector<int> all{1};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		all.push_back(a[i]);
		if (a[i] - d > 0) all.push_back(a[i] - d);
		all.push_back(a[i] + d);
	}
	
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	auto id = [&] (int x) {
		return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
	};

	int sz = all.size();
	for (int i = 1; i <= n; i++) {
		pair<int, int> x = make_pair(0, 0), y;
		if (a[i] - d > 0) x = query(1, 1, sz, 1, id(a[i] - d));
		y = query(1, 1, sz, id(a[i] + d), sz);
		pair<int, int> mx = max(x, y);
		p[i] = -mx.second;
		dp[i] = mx.first + 1;
		update(1, 1, sz, id(a[i]), make_pair(dp[i], -i));
	}
	
	int mx = 0, idx = -1;
	for (int i = 1; i <= n; i++) if (dp[i] > mx) mx = dp[i], idx = i;
	
	cout << mx << '\n'; vector<int> ans;
	for (int cur = idx; cur != 0; cur = p[cur]) ans.push_back(cur);
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
}
