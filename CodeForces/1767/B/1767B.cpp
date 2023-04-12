#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int ans, n; cin >> n >> ans;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 1; i < n; i++) { int x; cin >> x; pq.push(x); }
		while (!pq.empty()) {
			int x = pq.top(); pq.pop();
			if (x <= ans) continue;
			ans += (x - ans + 1) / 2;
		}
		cout << ans << '\n';
	}
}
