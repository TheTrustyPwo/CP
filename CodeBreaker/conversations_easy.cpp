#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a, b; cin >> n;
	stack<int> st; map<int, bool> m;
	while (n--) {
		cin >> a;
		if (a == 1) { cin >> b; st.push(b); }
		else if (a == 2) { cin >> b; m[b] = 1; }
		else if (a == 3) st.pop();
		else {
			if (st.empty()) cout << -1;
			else cout << st.top();
			cout << endl;
		}
		while (!st.empty() && m[st.top()]) st.pop();
	}
}
