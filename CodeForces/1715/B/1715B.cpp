#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		ll n, k, b, s; cin >> n >> k >> b >> s;
		if (s < k * b || s > (k * b + (k - 1) * n)) { cout << "-1\n"; continue; }
		s -= k * b; ll now = min(s, k - 1);
		cout << k * b + now << ' ';
		s -= now;
		for (int i = 1; i < n; i++) {
			now = min(s, k - 1);
			cout << now << ' ';
			s -= now;
		}
		cout << '\n';
	}
}
