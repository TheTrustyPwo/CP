#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, r, k; cin >> n >> r >> k;
	vector<int> a[n];
	for (int i = 0; i < r; i++) {
		int p, t; cin >> p >> t; p--;
		a[p].push_back(t - p);
	}
	
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		for (const int p : a[i]) pq.push(p);
		while (pq.size() > k) pq.pop();
		if (pq.size() < k) cout << -1 << ' ';
		else cout << pq.top() + i << ' ';
	}
}
