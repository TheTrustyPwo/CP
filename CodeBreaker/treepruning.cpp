#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, deg[400005];
vector<int> g[400005];
queue<int> cur, nxt;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for (int i = 0; i < n; i++) {
		deg[i] = g[i].size();
		if (deg[i] == 1) deg[i] = 0, cur.push(i);
	}
	
	int ans = 0;
	while (k--) {
		ans += cur.size();
		while (!cur.empty()) {
			int v = cur.front(); cur.pop();
			for (const int u : g[v]) {
				deg[u]--;
				if (deg[u] == 1) nxt.push(u);
			}
		}
		swap(cur, nxt);
	}
	
	cout << n - ans;
}
