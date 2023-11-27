#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	queue<pair<int, int>> q;
	map<int, int> mp, out;
	for (int i = 1; i <= n; i++) {
		int tp, c, f, t; cin >> tp;
		if (tp == 1) {
			cin >> c >> t >> f;
			q.push({c, t});
			mp[c] = f;
		} else if (tp == 2) {
			cin >> c >> f;
			mp[c] = f;
		} else if (tp == 3) {
			cin >> f;
			out[f] = 1;
		} else {
			while (!q.empty() && (q.front().second < i || out[mp[q.front().first]])) q.pop();
			if (q.empty()) cout << -1 << '\n';
			else { cout << q.front().first << '\n'; q.pop(); }
		}
	}
}
