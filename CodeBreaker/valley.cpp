#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200005, LOG = 20;

int n, s, q, e, depth[MAXN], dist[MAXN], pre[MAXN], post[MAXN], dp[MAXN], up[MAXN][LOG], mn[MAXN][LOG], timer = 1;
bool shop[MAXN];
vector<pair<int, int>> edges, g[MAXN];

void dfs(int v, int p, int d) {
	pre[v] = ++timer, dist[v] = dist[p] + d;
	if (v != e) depth[v] = depth[p] + 1;
	for (const pair<int, int> u : g[v])
		if (u.first != p) dfs(u.first, v, u.second);
	
	dp[v] = 1e18;
	if (shop[v]) dp[v] = dist[v];
	else for (const pair<int, int> u : g[v])
			if (u.first != p) dp[v] = min(dp[v], dp[u.first]);
	
	post[v] = ++timer;
}

void twok(int v, int p) {
	up[v][0] = p;
	if (dp[v] == 1e18) mn[v][0] = 1e18;
	else mn[v][0] = dp[v] - 2 * dist[v];
	for (int i = 1; i < LOG; i++) up[v][i] = up[up[v][i - 1]][i - 1], mn[v][i] = min(mn[v][i - 1], mn[up[v][i - 1]][i - 1]);
	for (const pair<int, int> u : g[v])
		if (u.first != p) twok(u.first, v);
}

bool is_parent(int u, int par) {
	return pre[par] <= pre[u] && post[u] <= post[par];
}

int query(int v, int b) {
	if (!is_parent(v, b)) return -1;
	int cur = dist[v], diff = depth[v] - depth[b], ans = 1e18;
	for (int i = LOG - 1; i >= 0; i--)
		if (diff & 1 << i) ans = min(ans, mn[v][i]), v = up[v][i];
	ans = min(ans, mn[v][0]);
	if (ans != 1e18) ans += cur;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s >> q >> e;
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
		edges.push_back(make_pair(a, b));
	}
	
	for (int i = 0; i < s; i++) {
		int x; cin >> x;
		shop[x] = true;
	}
	
	dfs(e, e, 0);
	twok(e, e);
	
	for (int i = 0; i < n - 1; i++)
		if (depth[edges[i].first] < depth[edges[i].second])
			swap(edges[i].first, edges[i].second);
			
	while (q--) {
		int b, r; cin >> b >> r;
		int ans = query(r, edges[b - 1].first);
		if (ans == -1) cout << "escaped";
		else if (ans == 1e18) cout << "oo";
		else cout << ans;
		cout << "\n";
	}
}
