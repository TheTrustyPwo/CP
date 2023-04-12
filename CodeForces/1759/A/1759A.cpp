#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		bool flag = false;
		if (s.size() == 1 && s[0] != 'Y' && s[0] != 'e' && s[0] != 's') flag = true;
		for (int i = 0; i < s.size() - 1; i++) {
			if ((s[i] == 'Y' && s[i + 1] != 'e') || (s[i] == 'e' && s[i + 1] != 's') || (s[i] == 's' && s[i + 1] != 'Y')) { flag = true; break; }
		}
		cout << (flag ? "NO\n" : "YES\n");
	}
}
