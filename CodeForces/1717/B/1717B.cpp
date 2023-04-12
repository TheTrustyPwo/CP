#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, k, r, c; cin >> n >> k >> r >> c;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				if ((i + j) % k == (r + c) % k) cout << 'X';
				else cout << '.';
			cout << '\n';
		}
	}
}
