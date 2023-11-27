#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	if (k == 0) { cout << 0; return 0; }
  
	int ans = a[0]; k--; int stop = -1;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(a[0]);
	for (int i = 1; i < n; i++) {
		if (k < 2) {
			stop = i - 1;
			break;
		}
		ans += a[i];
		k -= 2;
		pq.push(a[i]);
	}
	
	if (stop == -1) { cout << ans; return 0; }

	int cur = ans;
	for (int i = stop + 1; i < n; i++) {
		if (a[i] <= pq.top()) continue;
		
		int required = i - stop + 1 - k;
		if (pq.size() < required) break;
		
		for (int i = 0; i < required; i++) {
			cur -= pq.top();
			pq.pop();
		}
		
		cur += a[i];
		pq.push(a[i]);
		stop = i;
		ans = max(ans, cur);
	}
	
	cout << ans;
}
