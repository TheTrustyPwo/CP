#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	unordered_map<int, int> m; unordered_set<int> s; pair<int, int> a[n];
	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		a[i] = make_pair(u, v);
		s.insert(v);
	}
	
	sort(a, a + n);
	int ans = 1e9;
	queue<pair<int, int>> q; q.push(a[0]);
	m[a[0].second]++;
	for (int i = 1; i < n; i++) {
		if (m.size() == s.size())
			ans = min(ans, q.back().first - q.front().first);
		q.push(a[i]); m[a[i].second]++;
		while (m[q.front().second] > 1) {
			m[q.front().second]--;
			q.pop();
		}
	}
	
	if (m.size() == s.size()) ans = min(ans, q.back().first - q.front().first);
	cout << ans;
}
