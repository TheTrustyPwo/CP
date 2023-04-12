#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;

int n, k, cnt[MAXN], mx[MAXN], ans = 0;
bool cats[MAXN], visited[MAXN];
vector<int> g[MAXN];

bool leaf(int v) {
	return (g[v].size() == 1 && visited[g[v][0]]);
	for (const int u : g[v])
		if (!visited[u]) return false;
	return true;
}

void dfs(int v) {
	visited[v] = true;
	for (const int u : g[v]) {
		if (visited[u]) continue;
		if (cats[u]) cnt[u] = cnt[v] + 1;
		else cnt[u] = 0;
		mx[u] = max(mx[v], cnt[u]);
		if (leaf(u) && mx[u] <= k) ans++;
		dfs(u);
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> cats[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	cnt[1] = mx[1] = cats[1];
	dfs(1);
	
	cout << ans;
}
