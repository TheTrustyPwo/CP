#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unordered_map<int, int> umap;

umap t[1048576];
int n, q, a[500005];

umap combine(const umap &m1, const umap &m2) {
	umap res;
	for (const auto &i : m1) res[i.first] += i.second;
	for (const auto &i : m2) res[i.first] += i.second;
	for (auto it = res.begin(); it != res.end(); ) {
		if ((*it).second > 2) res.erase(it++);
		else ++it;
	}
	return res;
}

void build(int idx, int l, int r) {
	if (l == r) { t[idx][a[l]] = 1; return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
}

umap query(int idx, int l, int r, int tl, int tr) {
	if (tl > tr) return umap();
	if (l == tl && r == tr) return t[idx];
	int m = (l + r) / 2;
	return combine(query(idx * 2, l, m, tl, min(tr, m)), query(idx * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	build(1, 1, n);
	
	while (q--) {
		int l, r; cin >> l >> r;
		umap m = query(1, 1, n, l, r);
		int cnt = 0;
		for (const auto &i : m) if (i.second == 2) cnt++;
		cout << cnt << '\n';
	}
}
