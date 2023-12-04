#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	pair<int, int> b[n]; for (int i = 0; i < n; i++) cin >> b[i].first >> b[i].second;
	
	sort(a, a + n); sort(b, b + n);
	
	int l = 0, r = 1e9, ans = -1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		int idx = 0, bball = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (; idx < n; idx++)
			if (b[idx].first <= a[0] + m) pq.push(b[idx].second + m);
			else break;
		while (!pq.empty()) {
			int x = pq.top(); pq.pop();
			if (a[bball] <= x) {
				bball++;
				for (; idx < n; idx++)
					if (b[idx].first <= a[bball] + m) pq.push(b[idx].second + m);
					else break;
			} else break;
		}
		
		if (bball < n) l = m + 1;
		else {
			r = m - 1;
			ans = m;
		}
	}
	
	cout << ans;
}
