#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string a, b; cin >> a >> b;
		char ca = a.back(), cb = b.back();
		if (ca == cb) {
			if (a == b) cout << '=';
			else if (ca == 'S') cout << (a.size() < b.size() ? '>' : '<');
			else cout << (a.size() < b.size() ? '<' : '>');
		} else cout << (ca < cb ? '>' : '<');
		cout << '\n';
	}
}
