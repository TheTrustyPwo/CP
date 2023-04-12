#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e, k, m, a, b, c;
bool ents[2000000];
int dist[2000000], cost[2000000];
vector<int> ans;
vector<pair<int, int>> g[2000000];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e >> m >> k;
	
	for (int i = 0; i < m; i++) {
		cin >> a;
		ents[a] = true;
	}
	
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		g[b].push_back(make_pair(a, c));
	}
	
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(n - 1);
	dist[n - 1] = 0;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (const auto it : g[c]) {
			if (dist[it.second] != -1) continue;
			dist[it.second] = dist[c] + 1;
			q.push(it.second);
		}
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, n - 1));
	cost[n - 1] = 0;
	while (!pq.empty()) {
		auto c = pq.top();
		pq.pop();
		if (c.first != cost[c.second]) continue;
		for (const auto it : g[c.second]) {
			if (cost[it.second] == -1 || c.first + it.first < cost[it.second]) {
				cost[it.second] = c.first + it.first;
				pq.push(make_pair(cost[it.second], it.second));
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (dist[i] < k) cost[i] = LONG_LONG_MAX;
		if (!ents[i]) cost[i] = LONG_LONG_MAX;
	}
	
	int m = *min_element(cost, cost + n);
	for (int i = 0; i < n; i++) {
		if (cost[i] == m && dist[i] >= k && ents[i])
			ans.push_back(i);
	}
	
	sort(ans.begin(), ans.end());
	if (!ans.size()) {
		cout << -1;
		return 0;
	}
	
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++)
		cout << ' ' << ans[i];
		
	return 0;
}
