#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n; cin >> n;
	ll mn = n;
	for (ll i = 1; i < n / 2; i++) {
		ll p = pow(2, i);
		mn = min(mn, i + n / p + (n % p != 0));
	}
	cout << mn;
}
