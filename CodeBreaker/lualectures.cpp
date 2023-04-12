#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<pair<int, pair<bool, int>>> events;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		events.push_back(make_pair(a, make_pair(1, i)));
		events.push_back(make_pair(b + 1, make_pair(0, i)));
	}
	sort(events.begin(), events.end());
	
	int ans[n], k = 0;
	stack<int> st;
	for (const auto p : events) {
		if (p.second.first) {
			if (st.empty()) st.push(++k);
			ans[p.second.second] = st.top();
			st.pop();
		} else {
			st.push(ans[p.second.second]);
		}
	}
	
	cout << k << endl;
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
