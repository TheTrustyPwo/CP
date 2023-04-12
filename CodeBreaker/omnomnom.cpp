#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> g[n];
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int cnt = 0;
	queue<pair<int, int>> q; q.emplace(0, 0);
	bool visited[n]{}; visited[0] = 1;
	while (!q.empty()) {
		int cur = q.front().first, d = q.front().second; q.pop();
		if (d % 2 == 0) cnt++;
		for (const int p : g[cur]) {
			if (visited[p]) continue;
			visited[p] = 1;
			q.emplace(p, d + 1);
		}
	}
	
	cout << max(cnt, n - cnt);
}
