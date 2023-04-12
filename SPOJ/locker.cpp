#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

ll multiply(ll a, ll b) {
	if (a == 0) return 0;
	a %= M, b %= M;
	if (a & 1) return multiply(multiply(2, (a / 2)), b);
	else return multiply(multiply(2, ((a - 1) / 2)), b) + b;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		vector<bool> prime(n + 1, true);
		prime[0] = prime[1] = false;
		for (ll i = 2; i * i <= n; i += 2) {
			if (prime[i]) {
				for (ll j = i * i; j <= n; j += i)
					prime[j] = false;
			}
		}
		
		ll ans = 1;
		for (ll i = 0; i <= n; i++) {
			if (prime[i]) ans *= i;
		}
		
		cout << ans << '\n';
	}
}
