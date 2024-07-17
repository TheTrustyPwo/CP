#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, ans = 0, st[1000005], sz[1000005], cnt[1000005];
vector<int> g[1000005];

void dfs(int v, int p) {
	sz[v] = 1, cnt[v] = st[v];
	for (const int u : g[v]) {
		if (u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
		cnt[v] += cnt[u];
	}
	ans += abs(sz[v] - cnt[v]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, s; cin >> u >> s;
		if (u != -1) {
			g[u].push_back(i);
			g[i].push_back(u);
		}
		st[i] = s;
	}
	
	dfs(0, 0);
	cout << ans;
}
