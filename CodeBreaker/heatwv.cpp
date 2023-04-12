#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, c, x, y; cin >> t >> c >> x >> y; x--; y--;
	vector<pair<int, int>> g[t];
	for (int i = 0; i < c; i++) {
		int a, b, w; cin >> a >> b >> w; a--; b--;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}
	int dist[t]; for (int i = 0; i < t; i++) dist[i] = INT_MAX;
	dist[x] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, x));
	
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
	
	cout << dist[y];
}
