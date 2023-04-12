#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, e; cin >> v >> e;
	vector<pair<int, int>> g[v];
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	
	int dist[v]; fill(dist, dist + v, 2e9);
	int par[v]; fill(par, par + v, -1);
	int X[v]; fill(X, X + v, 0);
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push(make_pair(0, make_pair(0, -1)));
	
	while(!pq.empty()) {
		int d = pq.top().first, u = pq.top().second.first, p = pq.top().second.second; pq.pop();
		if (X[u]) continue;
		dist[u] = d; X[u] = 1; par[u] = p;
		for (const pair<int, int> it : g[u]) {
			if (!X[it.first]) pq.push(make_pair(d + it.second, make_pair(it.first, u)));
		}
	}
	
	cout << (dist[v - 1] == 2e9 ? -1 : dist[v - 1]);
}
