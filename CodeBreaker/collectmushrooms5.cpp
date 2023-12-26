#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m; pair<int, int> a[n];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		pq.emplace(a[i].first, i);
	}
	
	int cnt = 0, cost = 0;
	while (cnt < m) {
		int x = pq.top().first, y = pq.top().second;
		cnt++, cost += x;
		if (y < n) pq.emplace(a[y].second, n);
	}
	
	cout << cost;
}
