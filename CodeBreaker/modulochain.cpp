#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll m = 1e9 + 7;

int add(ll x, ll y) {
	return (x % m + y % m) % m;
}

int sub(ll x, ll y) {
	return ((x - y) % m) + ((x >= y) ? 0 : m);
}

int mul(ll x, ll y) {
	return ((x % m) * (y % m)) % m;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, a; cin >> n >> a;
	ll sum = 0, prod = a;
	for (int i = 2; i < n; i++) {
		ll b; cin >> b;
		sum = add(sum, b);
	}
	ll c; cin >> c;
	sum = add(sum, c), prod = mul(prod, c);
	cout << add(sum, a) << '\n' << prod << '\n' << sub(a, sum);
}
