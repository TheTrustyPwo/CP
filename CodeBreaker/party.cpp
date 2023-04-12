#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, ans = -1; cin >> n >> m;
	vector<int> g[n];
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	bool visited[n]{}; visited[0] = true;
	queue<pair<int, int>> q; q.push(make_pair(0, 0));
	
	while (!q.empty()) {
		int cur = q.front().first, d = q.front().second; q.pop();
		ans++;
		for (const int e : g[cur]) {
			if (visited[e] || d == 2) continue;
			visited[e] = true;
			q.push(make_pair(e, d + 1));
		}
	}
	
	cout << ans;
}
