#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n; n--;
		ll ans = (((n * (n + 1)) % mod) * ((2 * n + 1) % mod)) % mod;
		ans = (ans * 333333336) % mod;
		ans = (ans + ((n * (n + 1)) / 2) % mod) % mod;
		ans = (ans + ((n + 1) * (n + 1)) % mod) % mod;
		ans = (ans * 2022) % mod;
		cout << ans << "\n";
	}
}
