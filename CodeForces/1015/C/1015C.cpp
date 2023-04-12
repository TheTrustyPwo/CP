#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	ll cur = 0, diff[n];
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		cur += a;
		diff[i] = a - b;
	}
	
	sort(diff, diff + n, greater<ll>());
	int idx = 0;
	while (cur > m && idx < n) {
		cur -= diff[idx];
		idx++;
	}
	
	if (cur > m) cout << -1;
	else cout << idx;
}
