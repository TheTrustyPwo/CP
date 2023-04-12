#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string latin = "abcdefghijklmnopqrstuvwxyz";
	unordered_map<char, int> mp;
	for (int i = 0; i < 26; i++) mp[latin[i]] = i + 1;
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = 0;
		for (const char ch : s) ans = max(ans, mp[ch]);
		cout << ans << '\n';
	}
}
