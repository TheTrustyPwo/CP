#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005

int n, m, a, b, c, d1[N], d2[N], d3[N];
bool visited[N]{};
vector<pair<int, int>> g[N], h[N];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> a >> b >> c;
	for (int i = 0; i < m; i++) {
		int u, v, f, s; cin >> u >> v >> f >> s;
		g[u].push_back(make_pair(v, f));
		g[v].push_back(make_pair(u, f));
		h[u].push_back(make_pair(v, s + f));
		h[v].push_back(make_pair(u, s + f));
	}
	
	fill(d1, d1 + N, 1e16); d1[a] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, a);
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (visited[u] || du != d1[u]) continue;
		visited[u] = true;
		for (const pair<int, int> &p : g[u]) {
			int n = p.first, w = p.second;
			if (d1[n] > d1[u] + w) {
				d1[n] = d1[u] + w;
				pq.emplace(d1[n], n);
			}
		}
	}

	fill(d2, d2 + N, 1e16); d2[c] = 0;
	memset(visited, 0, sizeof(visited));
	pq.emplace(0, c);
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (visited[u] || du != d2[u]) continue;
		visited[u] = true;
		for (const pair<int, int> &p : g[u]) {
			int n = p.first, w = p.second;
			if (d2[n] > d2[u] + w) {
				d2[n] = d2[u] + w;
				pq.emplace(d2[n], n);
			}
		}
	}

	fill(d3, d3 + N, 1e16); d3[b] = 0;
	memset(visited, 0, sizeof(visited));
	pq.emplace(0, b);
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (visited[u] || du != d3[u]) continue;
		visited[u] = true;
		for (const pair<int, int> &p : h[u]) {
			int n = p.first, w = p.second;
			if (d3[n] > d3[u] + w) {
				d3[n] = d3[u] + w;
				pq.emplace(d3[n], n);
			}
		}
	}
	
	int ans = 1e16;
	for (int i = 1; i <= n; i++) ans = min(ans, d1[i] + d2[i] + d3[i]);
	cout << ans;
}
