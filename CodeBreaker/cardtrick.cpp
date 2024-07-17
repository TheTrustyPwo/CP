#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	priority_queue<int> pq;
	for (int i = 0; i < k; i++) pq.push(a[i]);
	int cur = 1e9, ans = 0, idx = k;
	while (!pq.empty()) {
		while (!pq.empty() && pq.top() > cur) pq.pop();
		if (pq.empty()) break;
		cur = pq.top(); pq.pop();
		ans++;
		if (idx < n) pq.push(a[idx++]);
	}
	cout << ans;
}
