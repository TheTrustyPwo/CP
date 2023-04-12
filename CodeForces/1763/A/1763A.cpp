#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int mx, mn; cin >> mx; mn = mx;
		for (int i = 1; i < n; i++) {
			int x; cin >> x;
			mx |= x;
			mn &= x;
		}
		
		cout << mx - mn << '\n';
	}
}
