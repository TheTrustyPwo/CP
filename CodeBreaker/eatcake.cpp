#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x, y, a[5005];

int solve(int l, int r, int offset) {
	if (l > r) return 0;
	if (l == r) return min(x * (a[l] - offset), y);
	int mn = 1e9; for (int i = l; i <= r; i++) mn = min(mn, a[i]);
	mn -= offset;
	int cost = mn * x;
	
	int start = l;
	for (int i = l; i <= r; i++)
		if (a[i] == mn + offset) cost += solve(start, i - 1, offset + mn), start = i + 1;
	cost += solve(start, r, offset + mn);
	
	int res = min(cost, (r - l + 1) * y);
	return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cout << solve(0, n - 1, 0);
}
