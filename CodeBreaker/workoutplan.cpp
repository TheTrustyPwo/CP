#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int x[n]; for (int i = 0; i < n; i++) cin >> x[i];
	int a; cin >> a;
	int c[n]; for (int i = 0; i < n; i++) cin >> c[i];
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		pq.push(c[i]);
		if (k >= x[i]) continue;
		while (!pq.empty() && k < x[i]) {
			ans += pq.top(); pq.pop();
			k += a;
		}
		if (k < x[i]) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}
