#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	map<string, string> a, b;
	for (int i = 0; i < n; i++) {
		string x, y; cin >> x >> y;
		a[x] = y;
		b[y] = x;
	}
	
	while (q--) {
		int t; string s; cin >> t >> s;
		if (t == 1) cout << a[s] << '\n';
		else cout << b[s] << '\n';
	}
}
