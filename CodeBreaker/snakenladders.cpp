#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, s; cin >> n >> s;
	vector<pair<int, bool>> g[n];
	
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= min(6, n - i - 1); j++)
			g[i].push_back(make_pair(i + j, 1));
	
	for (int i = 0; i < s; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].clear();
		g[a].push_back(make_pair(b, 0));
	}
	
	int dist[n];
	for (int i = 0; i < n; i++) dist[i] = INT_MAX;
	deque<int> q;
	dist[0] = 0;
	q.push_back(0);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (auto e : g[v]) {
			if (dist[e.first] > dist[v] + e.second) {
				dist[e.first] = dist[v] + e.second;
				if (e.second == 0)
					q.push_front(e.first);
				else
					q.push_back(e.first);
			}
		}
	}

	cout << (dist[n - 1] > n ? -1 : dist[n - 1]);
}
