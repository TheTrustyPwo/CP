#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int g[n][m];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> g[i][j];
	
	int l = 0, r = 1e9, ans = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		
		bool b = false;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) if (g[i][j] >= mid) cnt++;
			if (cnt >= 2) { b = true; break; }
		}
		
		for (int i = 0; i < m; i++) {
			bool has = false;
			for (int j = 0; j < n; j++) if (g[j][i] >= mid) { has = true; break; }
			if (!has) { b = false; break; }
		}
		
		if (b) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	
	cout << ans;
}
