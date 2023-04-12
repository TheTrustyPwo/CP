#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, t; cin >> n >> t;
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
		ans += (t / i);
	cout << ans;
}
