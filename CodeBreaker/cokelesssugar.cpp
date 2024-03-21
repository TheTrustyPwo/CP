#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	priority_queue<int> pq; int ans = 0;
	for (int i = 0; i <= m; i++) pq.push(0);
	for (int i = 0; i < n; i++) {
		int x = pq.top(); pq.pop();
		ans += x;
		pq.push(x + a[i]);
	}
	cout << ans;
}
