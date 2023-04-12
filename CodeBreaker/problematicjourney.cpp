#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e, k;
vector<pair<int, int>> g[200005];

bool valid(int x) {
	queue<pair<int, int>> q; q.emplace(0, 0);
	bool visited[n]{}; visited[0] = 1;
	while (!q.empty()) {
		int cur = q.front().first, d = q.front().second; q.pop();
		if (cur == n - 1) return d <= k;
		for (const pair<int, int> p : g[cur]) {
			if (visited[p.first] || p.second > x) continue;
			visited[p.first] = 1;
			q.emplace(p.first, d + 1);
		}
	}
	
	return false;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e >> k;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	
	int l = 0, r = INT_MAX;
	while (l < r) {
		int mid = (l + r) / 2;
		if (valid(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << (l == INT_MAX ? -1 : l);
}
