#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, s[1005], h[1005], w[1005], p[1005], dp[2005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i] >> s[i] >> h[i];
	
	iota(p, p + n, 0);
	sort(p, p + n, [&](const int &a, const int &b) {
		return w[a] + s[a] < w[b] + s[b];
	});
	
	for (int i = 0; i < n; i++) {
		int x = p[i];
		for (int j = s[x]; j >= 0; j--) {
			dp[j + w[x]] = max(dp[j + w[x]], dp[j] + h[x]);
		}
	}
	
	cout << *max_element(dp, dp + 2005);
}
