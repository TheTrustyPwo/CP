#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	set<int> st;
	while (q--) {
		string s; cin >> s;
		if (s == "TRANSMIT") {
			int a, b; cin >> a >> b;
			auto it = st.lower_bound(a);
			if (*it > b || it == st.end()) cout << "YES";
			else cout << "NO";
			cout << endl;
		} else if (s == "SLEEP") {
			int a; cin >> a;
			st.insert(a);
		} else {
			int a; cin >> a;
			st.erase(a);
		}
	}
}
