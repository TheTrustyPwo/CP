#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e, m, k, et[10005];
vector<pair<int, int>> g[10005];

bool bfs(int end) {
	queue<pair<int, int>> q;
	bool visited[10005]{};
	q.push(make_pair(n - 1, 0));
	visited[n - 1] = true;
	while (!q.empty()) {
		int cur = q.front().first, d = q.front().second;
		if (cur == end) return d >= k;
		q.pop();
		for (const pair<int, int> p : g[cur]) {
			if (visited[p.first]) continue;
			visited[p.first] = true;
			q.push(make_pair(p.first, d + 1));
		}
	}
	
	return false;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e >> m >> k;
	for (int i = 0; i < m; i++) cin >> et[i];
	for (int i = 0; i < e; i++) {
		int a, b, f; cin >> a >> b >> f;
		g[b].push_back(make_pair(a, f));
	}
	
	vector<int> ans;
	for (int i = 0; i < m; i++)
		if (bfs(et[i])) ans.push_back(et[i]);
		
	if (ans.empty()) {
		cout << -1;
		return 0;
	}
	
	int dist[n]; for (int i = 0; i < n; i++) dist[i] = 1e9;
	dist[n - 1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, n - 1));
	
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (const pair<int, int> m : g[u]) {
			int v = m.first, w = m.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	
	int x = ans.size();
	
	int d[x];
	for (int i = 0; i < x; i++) d[i] = dist[ans[i]];
	int s = *min_element(d, d + x);
	set<int> f;
	for (int i = 0; i < x; i++)
		if (d[i] == s) f.insert(ans[i]);
	for (const int p : f) cout << p << ' ';
}
