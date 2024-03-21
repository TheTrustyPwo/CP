#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, depth[100005], bridge[100005];
bool visited[100005], ok = true;
vector<int> g[100005];
vector<pair<int, int>> ans;

void dfs(int v, int p) {
	visited[v] = 1;
	bridge[v] = depth[v] = depth[p] + 1;
	for (const auto it : g[v]) {
		if (it == p) continue;
		if (depth[v] < depth[it]) continue;
		if (visited[it]) bridge[v] = min(bridge[v], depth[it]);
		else dfs(it, v);
		bridge[v] = min(bridge[v], bridge[it]);
		ans.push_back({v, it});
	}
	
	if (bridge[v] == depth[v] && p != 0) ok = false;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1, 0);
	if (ok && ans.size() == m) for (const auto it : ans) cout << it.first << ' ' << it.second << '\n';
	else cout << "IMPOSSIBLE";
}
