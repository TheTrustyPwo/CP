#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<pair<int, int>> g[n];
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w; a--; b--;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}
	
	int d[n], p[n]; fill(d, d + n, 1e18); fill(p, p + n, -1);
	d[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (du != d[u]) continue;
		for (const auto &v : g[u]) {
			if (d[u] + v.second < d[v.first]) {
				d[v.first] = d[u] + v.second;
				p[v.first] = u;
				pq.push(make_pair(d[v.first], v.first));
			}
		}
	}
	
	if (d[n - 1] == 1e18) {
		cout << -1;
		return 0;
	}

	vector<int> path;
	for (int v = n - 1; v != 0; v = p[v])
		path.push_back(v);
	path.push_back(0);
	reverse(path.begin(), path.end());
	
	for (const int i : path) cout << i + 1 << ' ';
}
