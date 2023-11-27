#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_set<int> a[500005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int g[n][m];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> g[i][j];
	
	int l = 0, r = 1e9, ans = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		
		for (int i = 0; i < m; i++) a[i].clear();

		for (int j = 0; j < m; j++) for (int i = 0; i < n; i++) {
			if (g[i][j] >= mid) a[j].insert(i);
		}
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			bool ok = true;
			for (int j = 0; j < m; j++) {
				if (a[j].size() == 0 || (a[j].size() == 1 && a[j].find(i) != a[j].end())) {
					ok = false;
					break;
				}
			}
			if (ok) cnt++;
		}
		
		if (cnt >= m - 1) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	
	cout << ans;
}
