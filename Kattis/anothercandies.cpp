#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int rem = 0;
		for (int i = 0; i < n; i++) {
			int v; cin >> v;
			rem = (rem + v % n) % n;
		}
		if (rem == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}
