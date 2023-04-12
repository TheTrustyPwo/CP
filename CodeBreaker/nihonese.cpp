#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool vowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	int ans = 2;
	for (int i = 0; i < n; i++) {
		if (!vowel(s[i]) && s[i] != 'n' && !vowel(s[i + 1])) {
			ans--;
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		if (!vowel(t[i]) && t[i] != 'n' && !vowel(t[i + 1])) {
			ans--;
			break;
		}
	}
	if (ans == 0) cout << "zero";
	else if (ans == 1) cout << "wan";
	else cout << "su";
}
