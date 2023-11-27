#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	int l = 0, r = n, ans = -1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i].second >= cnt && a[i].first >= (m - cnt - 1)) cnt++;
		}
		
		if (cnt >= m) {
			ans = m;
			l = m + 1;
		} else r = m - 1;
	}
	
	cout << ans;
}
  
