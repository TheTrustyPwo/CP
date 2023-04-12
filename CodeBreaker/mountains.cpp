#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 400005;

int a[MAXN];
vector<int> t[4 * MAXN];

void build(int idx, int l, int r) {
	if (l == r) { t[idx] = vector<int>(1, a[l]); return; }
	int m = (l + r) >> 1;
	build(idx * 2, l, m);
	build(idx * 2 + 1, m + 1, r);
	merge(t[idx * 2].begin(), t[idx * 2].end(), t[idx * 2 + 1].begin(), t[idx * 2 + 1].end(), back_inserter(t[idx]));
}

int query(int idx, int l, int r, int a, int b, int x) {
	if (a > b) return 0;
	if (l == a && r == b) return lower_bound(t[idx].begin(), t[idx].end(), x) - t[idx].begin();
	int m = (l + r) >> 1;
	return query(idx * 2, l, m, a, min(b, m), x) + query(idx * 2 + 1, m + 1, r, max(a, m + 1), b, x);
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n - 1);
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		int x = query(1, 0, n - 1, 0, i - 1, a[i]), y = query(1, 0, n - 1, i + 1, n - 1, a[i]);
		ans += x * y;
	}
	cout << ans;
}
