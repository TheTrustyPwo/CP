#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

vector<pair<int, int>> g[1005];

int dijkstra(int start, int end) {
	int dist[1005]; for (int i = 0; i < 1005; i++) dist[i] = INF;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (const auto m : g[u]) {
			int v = m.first, w = m.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	return (dist[end] == INF ? -1 : dist[end]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, e, h, t; cin >> n >> e >> h >> t;
	for (int i = 0; i < e; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back(make_pair(b, w));
	}
	int x = dijkstra(h, t), y = dijkstra(t, h);
	if (x == -1 || y == -1) cout << -1;
	else cout << x + y;
}
