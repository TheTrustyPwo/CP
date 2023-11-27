#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
pair<int, int> edges[10005];
vector<pair<int, int>> g[105];

int dijkstra(int s) {
	int d[n]; for (int i = 0; i < n; i++) d[i] = 1e9; d[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (du != d[u]) continue;
		for (const auto v : g[u]) {
			int next = v.first, w = v.second;
			if ((u == edges[s].first && next == edges[s].second) || (next == edges[s].first && u == edges[s].second)) w *= 2;
			if (d[u] + w < d[next]) {
				d[next] = d[u] + w;
				pq.push(make_pair(d[next], next));
			}
		}
	}

	return d[n - 1];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w; a--; b--;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
		edges[i] = make_pair(a, b);
	}
	
	edges[m] = make_pair(-1, -1);
	int current = dijkstra(m), ans = 0;
	for (int i = 0; i < m; i++) {
		ans = max(ans, dijkstra(i) - current);
	}
	
	cout << ans;
}
