#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e, m, k, a, b, c;
unordered_map<int, bool> ent;
vector<pair<int, int>> g[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e >> m >> k;
	for (int i = 0; i < m; i++) { cin >> a; ent[a] = true; }
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		g[b].push_back(make_pair(a, c));
	}
	
	vector<int> valid;
	
	queue<pair<int, int>> q;
	bool visited[n]{};
	q.push(make_pair(n - 1, 0));
	visited[n - 1] = 1;
	while (!q.empty()) {
		int cur = q.front().first, d = q.front().second;
		q.pop();
		if (d >= k && ent[cur]) valid.push_back(cur);
		for (const pair<int, int> p : g[cur]) {
			if (visited[p.first]) continue;
			visited[p.first] = true;
			q.push(make_pair(p.first, d + 1));
		}
	}
	
	if (valid.empty()) {
		cout << -1;
		return 0;
	}
	
	int dist[n]; for (int i = 0; i < n; i++) dist[i] = 1e9;
	dist[n - 1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, n - 1));
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		for (const pair<int, int> p : g[u]) {
			int v = p.first, w = p.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	
	vector<int> validDist;
	for (const int p : valid) validDist.push_back(dist[p]);
	int mn = *min_element(validDist.begin(), validDist.end());
	
	set<int> ans;
	for (vector<int>::size_type i = 0; i < validDist.size(); i++)
		if (validDist[i] == mn) ans.insert(valid[i]);
		
	for (const int p : ans) cout << p << ' ';
}
