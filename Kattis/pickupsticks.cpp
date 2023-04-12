#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000005;

vector<int> g[MAXN];
int deg[MAXN];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		deg[b]++;
	}
	
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	
	vector<int> ans;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (auto u : g[cur]) {
			deg[u]--;
			if (deg[u] == 0) q.push(u);
		}
	}
	
	if (ans.size() == n) {
		for (auto e : ans) cout << e << '\n';
	} else cout << "IMPOSSIBLE";
}
