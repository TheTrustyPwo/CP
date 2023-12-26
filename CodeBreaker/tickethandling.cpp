#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int q; cin >> q;
	priority_queue<pair<pair<int, int>, int>> pq;
	while (q--) {
		int t, a, b; cin >> t;
		if (t == 1) {
			cin >> a >> b;
			pq.push({{a, q}, b});
		} else {
			if (pq.empty()) { cout << "-1\n"; continue; }
			cout << pq.top().second << '\n';
			pq.pop();
		}
	}
}
