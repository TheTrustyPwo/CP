#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, d; cin >> n >> d;
	unordered_set<int> g[n + 1];
	for (int i = 0; i < d; i++) {
		int c, f, a; cin >> c >> f;
		int prev = f;
		for (int j = 1; j < c; j++) {
			cin >> a;
			g[a].insert(prev);
			prev = a;
		}
		g[f].insert(prev);
	}
	
	queue<int> q; q.push(n);
	bool visited[n + 1]{}; visited[n] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (const int p : g[cur]) {
			if (visited[p] || g[p].find(cur) != g[p].end()) continue;
			visited[p] = 1;
			q.push(p);
		}
	}
	
	for (int i = 1; i <= n; i++) cout << visited[i] << ' ';
}
