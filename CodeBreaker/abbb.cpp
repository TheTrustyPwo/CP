#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'B') {
				if (st.empty()) st.push('B');
				else st.pop();
			} else st.push('A');
		}
		cout << st.size() << endl;
	}
}
