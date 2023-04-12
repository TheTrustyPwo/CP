#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		if (s.size() <= 10) { cout << s << '\n'; continue; }
		cout << s[0] << s.size() - 2 << s[s.size() - 1] << '\n';
	}
}
