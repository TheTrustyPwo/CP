#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_set<int> s;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			s.insert(x);
		}
		if (s.size() <= 2) cout << n / 2 + 1 << '\n';
		else cout << n << '\n';
	}
}
