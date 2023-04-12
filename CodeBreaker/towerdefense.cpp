#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, e; cin >> n >> e;
	unordered_map<int, int> g[n];
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a][b] = (g[a][b] == 0 ? c : min(g[a][b], c));
		g[b][a] = (g[b][a] == 0 ? c : min(g[b][a], c));
	}
	
	int dist[n]; fill(dist, dist + n, 1e9);
	int paths[n]; fill(paths, paths + n, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 0)); dist[0] = 0; paths[0] = 1;
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		for (const auto [v, w] : g[u]) {
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
				paths[v] = paths[u] % m;
			} else if (dist[v] == dist[u] + w) paths[v] = ((paths[v] % m) + (paths[u] % m)) % m;
		}
	}
	
	cout << paths[n - 1] % m;
}
