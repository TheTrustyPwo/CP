#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	stack<int> st;
	unordered_set<int> deleted;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		int t, a; cin >> t;
		if (t == 1) {
			cin >> a;
			st.push(a);
		} else if (t == 2) {
			cin >> a;
			m[a] = i;
		} else if (t == 3) {
			st.pop();
		} else {
			if (st.empty()) cout << -1 << endl;
			else cout << st.top() << endl;
		}
		while (!st.empty() && m[st.top()] > 0) { st.pop(); m[st.top()]--; }
	}
}
