#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, depth[200005];
vector<int> g[200005];

void dfs(int v, int p) {
	for (const int u : g[v]) {
		if (u == p) continue;
		dfs(u, v);
		depth[u] = depth[v] + 1;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int v; cin >> v;
		g[i].push_back(v);
		g[v].push_back(i);
	}
	
	depth[1] = 0; dfs(1, 1);
	
	int q; cin >> q;
	while (q--) {
		int c, t; cin >> c >> t;
		t -= depth[c];
		
	}
}
