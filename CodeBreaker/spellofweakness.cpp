#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, d, k; cin >> n >> d >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int cost = a[i] / 2;
		if (d < cost) {
			cout << cnt;
			return 0;
		}
		d -= cost;
		cnt++;
	}
	
	queue<int> q;
	for (int i = 0; i < k; i++) q.push(i);
	
	for (int i = k; i < n; i++) {
		if (q.empty()) {
			if (d < a[i]) {
				cout << cnt;
				return 0;
			}
			d -= a[i];
			cnt++;
		} else {
			int t = q.front(); q.pop();
			int cost = a[t] / 2 + (a[t] % 2 != 0) + a[i] / 2;
			if (d < cost) {
				cout << cnt;
				return 0;
			}
			d -= cost;
			cnt++;
			q.push(i);
		}
	}
	
	cout << cnt;
}
