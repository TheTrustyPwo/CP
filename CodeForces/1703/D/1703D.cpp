#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string a[n];
		unordered_set<string> s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		
		bool ans[n];
		for (int j = 0; j < n; j++) {
			ans[j] = 0;
			for (int i = 1; i < (int) a[j].size(); i++) {
				if (s.find(a[j].substr(0, i)) != s.end() && s.find(a[j].substr(i, a[j].size() - i)) != s.end()) {
					ans[j] = 1;
					break;
				}
			}
		}
		
		for (bool b : ans) cout << b;
		cout << '\n';
	}
}
