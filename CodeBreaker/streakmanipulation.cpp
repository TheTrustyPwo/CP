#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k; string s; cin >> s;
		if (n < (k + k - 1)) cout << -1 << '\n';
		else {
			int tmp = min(m, n - k + 1);
			cout << tmp / k << '\n';
		}
	}
}
