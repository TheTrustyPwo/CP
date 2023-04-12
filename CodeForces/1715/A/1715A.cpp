#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		int ans = min(m + m - 1 + n - 1, n + n - 1 + m - 1);
		if (n == 1 && m == 1) ans = 0;
		cout << ans << '\n';
	}
}
