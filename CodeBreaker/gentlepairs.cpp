#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<double, double> a[n]; for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs((a[j].second - a[i].second) / (a[j].first - a[i].first)) <= 1) ans++;
		}
	} cout << ans;
}
