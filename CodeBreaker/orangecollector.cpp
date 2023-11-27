#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, t[262144][17];

int combine(int l, int r) {
	return max(l, r);
}

void build(int idx, int l, int r, int j) {
	if (l == r) { t[idx][j] = 0; return; }
	int m = (l + r) / 2;
	build(idx * 2, l, m, j);
	build(idx * 2 + 1, m + 1, r, j);
	t[idx][j] = combine(t[idx * 2][j], t[idx * 2 + 1][j]);
}

void update(int idx, int l, int r, int p, int v, int j) {
	if (l == r) { t[idx][j] = max(v, t[idx][j]); return; }
	int m = (l + r) / 2;
	if (p <= m) update(idx * 2, l, m, p, v, j);
	else update(idx * 2 + 1, m + 1, r, p, v, j);
	t[idx][j] = combine(t[idx * 2][j], t[idx * 2 + 1][j]);
}

int query(int idx, int l, int r, int tl, int tr, int j) {
	if (tl <= l && r <= tr) return t[idx][j];
	if (tl > r || l > tr) return 0;
	int m = (l + r) / 2;
	return combine(query(idx * 2, l, m, tl, tr, j), query(idx * 2 + 1, m + 1, r, tl, tr, j));
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a[n + 1][4];
	for (int i = 1; i <= n; i++) for (int j = 0; j < 4; j++) cin >> a[i][j];
	
	for (int i = 0; i < 17; i++) build(1, 1, 1e5, i);
	
	int dp[n + 1]; dp[0] = 0; int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 0; j < 17; j++)
			if (((1 << j) & a[i][1]) != 0) tmp = max(tmp, query(1, 1, 1e5, a[i][2], a[i][3], j));
		dp[i] = tmp + a[i][0];
		ans = max(ans, dp[i]);
		
		for (int j = 0; j < 17; j++)
			if (((1 << j) & a[i][1]) != 0)
				update(1, 1, 1e5, a[i][1], dp[i], j);
	}
	
	// for (int i = 0; i <= n; i++) cout << dp[i] << ' '; cout << '\n';
	cout << ans;
}
