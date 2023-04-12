#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		int fl = 0, x = (n + k - 1) / k;
		for (int i = 0; i < m; i++) {
			int a; cin >> a;
			if (a == x) fl++;
			else if (a > x) fl = 1 << 30;
		}
		cout << (fl <= (n - 1) % k + 1 ? "YES" : "NO") << '\n';
	}
}
