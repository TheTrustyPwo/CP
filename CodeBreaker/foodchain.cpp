#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m = 1e9 + 9;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll ans = 1;
	for (int i = 0; i < 5; i++) {
		ll a; cin >> a;
		a %= m;
		ans = (ans * a) % m;
	}
	cout << ans;
}
