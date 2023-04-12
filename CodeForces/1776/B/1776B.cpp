#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; string s; cin >> n >> s; bool f = false;
		unordered_map<string, int> m;
		for (int i = 0; i < n - 1; i++) {
			string t = s.substr(i, 2);
			if (m.count(t)) {
				if (i - m[t] > 1) {
					cout << "YES\n";
					f = true;
					break;
				}
			} else m[t] = i;
		}
		
		if (!f) cout << "NO\n";
	}
}
