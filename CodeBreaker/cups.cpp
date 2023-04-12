#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;

struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll add = 0, q; cin >> q;
	__gnu_pbds::gp_hash_table<ll, bool, chash> m;
	while (q--) {
		ll t, x; cin >> t >> x;
		if (t == 1) cout << (m[x - add] ? "YES\n" : "NO\n");
		else if (t == 2) m[x - add] = 1;
		else add += x;
	}
}
