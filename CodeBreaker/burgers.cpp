#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x[100005], a[100005], b[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	int l = 0, r = 1e9, ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		int upper = 1e9, lower = 0;
		for (int i = 0; i < n; i++) {
			if (min(a[i], b[i]) * m > x[i]) upper = -1;
			if (a[i] < b[i]) {
				int leftover = x[i] - a[i] * m;
				int maxb = leftover / (b[i] - a[i]);
				lower = max(lower, m - maxb);
			} else if (a[i] > b[i]) {
				int leftover = x[i] - b[i] * m;
				int maxa = leftover / (a[i] - b[i]);
				upper = min(upper, maxa);
			}
		}
		if (upper >= lower) l = m + 1, ans = m;
		else r = m - 1;
	}
	
	cout << ans;
}
