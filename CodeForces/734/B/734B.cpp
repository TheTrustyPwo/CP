#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll x = min({a, c, d}), y = min(b, a - x);
	cout << x * 256 + y * 32;
}
