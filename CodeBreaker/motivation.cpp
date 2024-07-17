#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	priority_queue<int, vector<int>, greater<int>> pq;
	int ans = 0, x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(a[i]);
		ans += a[i];
		if (x == 1) {
			ans -= pq.top();
			pq.pop();
		}
	}
	cout << ans;
}
