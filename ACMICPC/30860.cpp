#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> a[n]; for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	int cnt = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur > a[i].second) cur = 0, cnt++;
		cur = max(cur, a[i].first);
	}
	
	if (cur > 0) cnt++;
	
	cout << cnt;
}
