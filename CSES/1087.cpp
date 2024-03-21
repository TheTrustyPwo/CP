#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s; cin >> s;
	set<char> st{'A', 'C', 'G', 'T'};
	for (int i = 0; i < s.size(); i++) {
		st.erase(s[i]);
		if (st.empty()) {
			cout << s[i];
			st = {'A', 'C', 'G', 'T'};
		} 
		if (i == s.size() - 1) cout << *st.begin();
	}
}
