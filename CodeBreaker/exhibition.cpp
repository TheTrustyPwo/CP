#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	pair<int, int> p[n]; for (int i = 0; i < n; i++) cin >> p[i].second >> p[i].first;
	int c[m]; for (int i = 0; i < m; i++) cin >> c[i];
	
	sort(p, p + n, greater<pair<int, int>>());
	sort(c, c + m, greater<int>());
	
	int j = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		while (j < n && p[j].second > c[i]) j++;
		if (j == n) break;
		ans++;
		j++;
	}
	
	cout << ans;
}
