#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int ans = 0; bool b = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ans += min(x, max(k - 1, 0));
		if (x >= k) b = 1;
	}
	
	if (b) cout << ans + 1;
	else cout << -1;
}
