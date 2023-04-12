#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q, k, m;
ll ft[1000005];

ll query(ll x) {
	ll ans = 0;
	for (; x; x -= (x & -x)) { ans += ft[x]; ans %= m; }
    return ans;
}

void update(ll x, ll v) {
	for (; x <= n; x += (x & -x)) { ft[x] += v; ft[x] %= m; }
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q >> k;
	m = (ll) 1 << k;
	while (q--) {
		ll t, a, b; cin >> t;
		if (t == 1) {
			cin >> a;
			cout << query(a) << "\n";
		} else {
			cin >> a >> b;
			update(a, b);
		}
	}
}
