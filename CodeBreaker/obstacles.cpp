#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n], dp[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int lo = 0, hi = 2000000013;
	while (hi > lo) {
		int mid = (lo + hi) / 2;
		dp[0] = 0;
		for (int i = 1; i < n; i++)
			dp[i] = k + 1;
		for (int i = 1; i < n; i++) {
			dp[i] = min(dp[i], i);
			for (int j = i - 1; j >= 0; j--) {
				if (abs(a[i] - a[j]) <= (i - j) * mid) {
					dp[i] = min(dp[i], dp[j] + (i - j - 1));
				}
			}
			if (dp[i] + n - 1 - i <= k) {
				dp[n - 1] = k;
				break;
			}
		}
		if (dp[n - 1] <= k) hi = mid;
		else lo = mid + 1;
	}
	cout << lo;
}
