#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

int n, p, a[MAXN];
vector<int> t[4*MAXN];

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = vector<int>(1, a[l]); return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	merge(t[idx * 2].begin(), t[idx * 2].end(), t[idx * 2 + 1].begin(), t[idx * 2 + 1].end(), back_inserter(t[idx]));
}

int query(int idx, int l, int r, int a, int b, int x) {
	if (a > b) return 0;
	if (l == a && r == b) {
		auto it = upper_bound(t[idx].begin(), t[idx].end(), x);
		return (it == t[idx].end() ? 0 : distance(it, t[idx].end()));
	}
	int m = (l + r) / 2;
	return query(idx * 2, l, m, a, min(b, m), x) + query(idx * 2 + 1, m + 1, r, max(a, m + 1), b, x);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> p;
	for (int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n - 1);
	while (p--) {
		int s, e, c; cin >> s >> e >> c; s--; e--;
		int l = 0, r = 1e9 + 5;
		while (l < r) {
			int m = (l + r) / 2;
			// cout << s << ' ' << e << ' ' << m << ' ' << query(1, 0, n - 1, s, e, m) << endl;
			if (query(1, 0, n - 1, s, e, m) + 1 > c) l = m + 1;
			else r = m;
		}
		
		cout << l << "\n";
	}
}
