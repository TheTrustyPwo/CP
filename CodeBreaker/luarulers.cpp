#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int b[m + 1]; for (int i = 0; i < m; i++) cin >> b[i];
	
	b[m] = n + 1;
	sort(b, b + m + 1);
	
	int pre[n + 1]; pre[0] = 0;
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i - 1];
	
	int ans = 0;
	for (int i = 1; i < b[0]; i++) if (pre[i] == 0) ans++;
	
	unordered_map<int, int> mp;
	for (int i = 0; i < m; i++) {
		for (int j = b[i]; j < b[i + 1]; j++) mp[pre[j]]++;
		int mx = 0;
		for (const auto &it : mp) mx = max(mx, it.second);
		ans += mx;
		mp.clear();
	}
	
	cout << ans;
}
