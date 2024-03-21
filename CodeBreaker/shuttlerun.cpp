#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	pair<int, int> a[n]; for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	bool visited[n]{};
	int cur = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		int mx = -1, idx = -1, next = -1;
		for (int j = 0; j < n; j++) {
			if (visited[j]) continue;
			if (0 > mx && a[j].first <= cur && cur <= a[j].second) mx = 0, idx = j, next = cur;
			if (cur < a[j].first) {
				if (abs(a[j].first - cur) > mx) {
					mx = abs(a[j].first - cur);
					idx = j;
					next = a[j].first;
				}
			} else if (cur > a[j].second) {
				if (abs(a[j].second - cur) > mx) {
					mx = abs(a[j].second - cur);
					idx = j;
					next = a[j].second;
				}	
			}
		}
		visited[idx] = true;
		ans += mx;
		cur = next;
	}
	
	ans += abs(cur);
	
	cout << ans;
}
