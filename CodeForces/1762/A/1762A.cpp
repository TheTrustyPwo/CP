#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int odd = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x & 1) odd++;
		}
		
		if (odd & 1) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}
