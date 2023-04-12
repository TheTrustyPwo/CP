#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

void test_case(int test) {
    ll m, x; cin >> m >> x;
    ll k = 0;
    for (ll i = 0; i < 64; i++)
		if ((x & (1ll << i)) && !(m & (1ll << i))) { cout << -1 << '\n'; return; }
		else if (!(x & (1ll << i)) && (m & (1ll << i))) k |= (1ll << i);
    if (m == x) { cout << m << '\n'; return; }
    ll r = 0; while (k >>= 1ll) r++;
    for (ll i = 0; i < r; i++) m &= ~(1ll << i);
    if (r >= 63ll) { cout << -1 << '\n'; return; }
    m |= (1ll << (r));
    cout << m << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
