#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> a[n];
	pair<int, int> s[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		s[i].first = a[i].first + a[i].second;
		s[i].second = i;
	}
	
	sort(s, s + n);
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int idx = s[i].second;
		if (i < (n + 1) / 2) ans += min(a[idx].first, a[idx].second);
		else ans -= max(a[idx].first, a[idx].second);
	}
	
	cout << ans;
}
