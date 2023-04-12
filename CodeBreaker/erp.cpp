#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e, dist1[50005], dist2[50005];
vector<pair<int, int>> g[50005];

void dijkstra(int start, int *dist) {
	fill(dist, dist + n, 1e9);
	bool visited[50005]{};
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int d = pq.top().first, u = pq.top().second; pq.pop();
		if (visited[u]) continue;
		dist[u] = d, visited[u] = 1;
		for (const pair<int, int> p : g[u])
			if (!visited[p.first]) pq.push(make_pair(d + p.second, p.first));
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, e, k; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	
	dijkstra(0, dist1);
	dijkstra(n - 1, dist2);
	
	cin >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		int mn = 1e9;
		if (dist1[a] != 1e9 && dist2[b] != 1e9) mn = min(mn, dist1[a] + dist2[b]);
		if (dist2[a] != 1e9 && dist2[a] != 1e9) mn = min(mn, dist2[a] + dist1[b]);
		int ans = dist1[n - 1] - mn - 1;
		cout << (ans < 0 ? -1 : ans) << "\n";
	}
}
