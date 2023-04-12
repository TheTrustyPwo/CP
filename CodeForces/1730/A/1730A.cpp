#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, c, ans = 0; cin >> n >> c;
		unordered_map<int, int> p;
		for (int i = 0; i < n; i++) {
			int o; cin >> o;
			p[o]++;
		}
		for (auto const &[key, val] : p) {
			if (val > c) ans += c;
			else ans += val;
		}
		cout << ans << endl;
	}
}
