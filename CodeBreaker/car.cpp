#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, e; cin >> n >> e;
	vector<pair<int, int>> g[n];
	for (int i = 0; i < e; i++) {
		int a, b, w; cin >> a >> b >> w; a--; b--;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}
	
	set<int> visited[n];
	int mileage[n]; for (int i = 0; i < n; i++) mileage[i] = INT_MAX;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	mileage[0] = 1;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int cur = q.top().second;
		q.pop();
		for (auto e : g[cur]) {
			int val = max(e.second, mileage[cur]);
			if (mileage[e.first] > val) mileage[e.first] = val;
			if (visited[e.first].find(cur) != visited[e.first].end()) continue;
			q.push(make_pair(val, e.first));
			visited[cur].insert(e.first);
			visited[e.first].insert(cur);
		}
	}
	
	cout << (mileage[n - 1] == INT_MAX ? -1 : mileage[n - 1]);
}
