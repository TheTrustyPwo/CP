#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		multiset<int> a;
		for (int i = 0; i < n; i++) { int x; cin >> x; a.insert(x); }
		int b[m]; for (int i = 0; i < m; i++) cin >> b[i];
		for (int i = 0; i < m; i++) {
			a.erase(a.begin());
			a.insert(b[i]);
		}
		int ans = 0;
		for (const int x : a) ans += x;
		cout << ans << '\n';
	}
}
