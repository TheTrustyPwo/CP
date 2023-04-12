#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; string s; cin >> s;
		bool flag = true;
		for (int i = 1; i < n; i += 3)
			if (s[i] != s[i + 1]) { flag = false; break; }
		cout << (flag ? "YES\n" : "NO\n");
	}
}
