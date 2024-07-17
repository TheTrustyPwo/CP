#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, depth[200005];
vector<int> g[200005];

void dfs(int v, int p, int d) {
	depth[v] = d;
	for (const int u : g[v])
		if (u != p) dfs(u, v, d + 1);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1, 1, 0);
	int mx = 0, idx = 1;
	for (int i = 1; i <= n; i++)
		if (depth[i] > mx) mx = depth[i], idx = i;
	dfs(idx, idx, 0);
	for (int i = 1; i <= n; i++)
		if (depth[i] > mx) mx = depth[i], idx = i;
	cout << mx;
}
