#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			cout << i << ' ' << i + 1;
			return 0;
		}
	}
	for (int i = 2; i < s.size(); i++) {
		if (s[i] == s[i - 2]) {
			cout << i - 1 << ' ' << i + 1;
			return 0;
		}
	}
	cout << "-1 -1";
}
