#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e, k;
vector<pair<int, int>> g[50005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}
	
	int dist1[n]; for (int i = 0; i < n; i++) dist1[i] = 1e9; dist1[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, 0);
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (du != dist1[u]) continue;
		for (const auto v : g[u]) {
			if (dist1[u] + v.second < dist1[v.first]) {
				dist1[v.first] = dist1[u] + v.second;
				pq.emplace(dist1[v.first], v.first);
			}
		}
	}
	
	while (!pq.empty()) pq.pop();
	int dist2[n]; for (int i = 0; i < n; i++) dist2[i] = 1e9; dist2[n - 1] = 0;
	pq.emplace(0, n - 1);
	while (!pq.empty()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (du != dist2[u]) continue;
		for (const auto v : g[u]) {
			if (dist2[u] + v.second < dist2[v.first]) {
				dist2[v.first] = dist2[u] + v.second;
				pq.emplace(dist2[v.first], v.first);
			}
		}
	}

	cin >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		int mn = 1e9;
		mn = min(mn, dist1[a] + dist2[b]);
		mn = min(mn, dist1[b] + dist2[a]);
		
		if (mn < dist2[0]) cout << dist2[0] - mn - 1 << '\n';
		else cout << -1 << '\n';
	}
}
