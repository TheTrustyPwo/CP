#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	int t = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		t += a[i].first;
		ans += a[i].second - t;
	}
	cout << ans;
}
