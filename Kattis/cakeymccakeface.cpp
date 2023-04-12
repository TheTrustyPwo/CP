#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int b[m]; for (int i = 0; i < m; i++) cin >> b[i];
	
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[j] - a[i] < 0) continue;
			mp[b[j] - a[i]]++;
		}
	}
	
	int mx = -1, ans = 0;
	for (auto const& [key, val] : mp) {
		if (val == mx) ans = min(ans, key);
		else if (val > mx) {
			mx = val;
			ans = key;
		}
	}
	
	cout << ans;
}
