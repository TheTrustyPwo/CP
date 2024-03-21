#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, depth[200005], pre[200005], post[200005], timer = 1;
vector<int> g[200005];
vector<int> st[200005];

void dfs(int v) {
	pre[v] = timer++;
	for (const int u : g[v]) {
		depth[u] = depth[v] + 1;
		dfs(u);
	}
	post[v] = timer - 1;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		g[x].push_back(i);
	}
	
	depth[1] = 0;
	dfs(1);
	
	for (int i = 1; i <= n; i++) st[depth[i]].push_back(pre[i]);
	for (int i = 1; i <= n; i++) sort(st[i].begin(), st[i].end());
	
	cin >> q;
	while (q--) {
		int c, t; cin >> c >> t;
		if (t < depth[c]) { cout << 0 << '\n'; continue; }
		cout << upper_bound(st[t].begin(), st[t].end(), post[c])
			- lower_bound(st[t].begin(), st[t].end(), pre[c]) << '\n';
	}
}
