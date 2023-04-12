#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	ll l[n+1], r[n];
	l[0] = 0; r[n] = 0;
	ll cur = 0, mx = 0;
	
	for (int i = 0; i < n; i++) {
		cur += a[i];
		mx = max(cur, mx);
		cur = max(cur, 0ll);
		l[i+1] = mx;
	}
	
	cur = 0, mx = 0;
	
	for (int i = n - 1; i >= 0; i--) {
		cur += a[i];
		mx = max(cur, mx);
		cur = max(cur, 0ll);
		r[i] = mx;
	}
	
	ll result = 0;
	for (int i = 0; i <= n; i++) result = max(result, l[i] + r[i]);
	cout << result;
}
