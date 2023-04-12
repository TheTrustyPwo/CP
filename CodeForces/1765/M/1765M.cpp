#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int ans = 1;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0) { ans = n / i; break; }
		cout << ans << ' ' << n - ans << '\n';
	}
}
