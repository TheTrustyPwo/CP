#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e;
vector<pair<int, bool>> g[200005];

int bfs(int start, bool b) {
	queue<pair<pair<int, int>, bool>> q;
	bool visited[200005][2]{};
	q.push(make_pair(make_pair(0, 0), b));
	visited[start][b] = 1;
	while (!q.empty()) {
		int cur = q.front().first.first, d = q.front().first.second;
		bool s = q.front().second; q.pop();
		if (cur == n - 1) return d;
		for (const pair<int, bool> n : g[cur]) {
			if (visited[n.first][s] || n.second != s) continue;
			visited[n.first][s] = 1;
			q.push(make_pair(make_pair(n.first, d + 1), !s));
		}
	}
	
	return 1e9;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b; bool c;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	
	int ans = min(bfs(0, 0), bfs(0, 1));
	if (ans == 1e9) cout << -1;
	else cout << ans;
}
