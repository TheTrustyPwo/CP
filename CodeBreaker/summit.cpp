#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool valid(ll m, ll d, ll k) {
	ll res = k, cur = d; d++;
	while (res < m) {
		if (k / cur < 1) return false;
		res += k / cur;
		cur *= d;
		d++;
	}
	return true;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll m, d; cin >> m >> d;
	ll l = min(m, d), r = m;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (valid(m, d, mid)) r = mid;
		else l = mid + 1;
	}
	cout << l;
}
