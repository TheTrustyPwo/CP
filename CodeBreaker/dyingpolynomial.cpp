#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll q, a, b, c, d;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> q;
	while (q--) {
		cin >> a >> b >> c >> d;
		ll l = 0, r = 1e5;
		while (l < r) {
			int m = (l + r) >> 1;
			if (a * m * m * m + b * m * m + c * m >= d) r = m;
			else l = m + 1;
		}
		cout << l << "\n";
	}
}
