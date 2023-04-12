#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, d; cin >> n >> d;
	ll ans = 0, mx = 0;
	for (ll i = 0; i < n; i++) {
		ll e; cin >> e;
		mx = max(e, mx);
		ans += e * e;
	}	
	ans -= mx * mx;
	ans += (mx + d) * (mx + d);
	cout << ans;
}
