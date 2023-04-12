#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, m, a; cin >> n >> m >> a;
	cout << (n / a + (n % a != 0)) * (m / a + (m % a != 0));
}
