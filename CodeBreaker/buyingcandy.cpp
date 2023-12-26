#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	pair<int, int> d[m]; for (int i = 0; i < m; i++) cin >> d[i].first >> d[i].second;
	
	sort(a, a + n);
	sort(d, d + m);
	
	int it1 = 0, it2 = 0, cur = 0;
	priority_queue<int> pq;
	for (; it2 < m; it2++) {
		if (d[it2].first > a[it1]) break;
		pq.push(d[it2].second);
	}
	while (it1 < n) {
		if (pq.empty()) cur += a[it1++];
		else {
			int x = pq.top(); pq.pop();
			// cout << a[it1] << ' ' << x << '\n';
			cur += a[it1++] - x;
		}
		for (; it2 < m; it2++) {
			if (d[it2].first > a[it1]) break;
			pq.push(d[it2].second);
		}
	}
	cout << cur;
}
