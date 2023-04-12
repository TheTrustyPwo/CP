#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		if (s == "yes") cout << "YES\n";
		else cout << "NO\n";
	}
}
