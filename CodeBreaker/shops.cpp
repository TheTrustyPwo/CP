#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e;
int p[500005], sz[500005];
bool visited[500005], ans[500005];
vector<pair<int, pair<int, int>>> edges;
vector<int> g[500005];

void make_set(int i) {
	p[i] = i;
	sz[i] = 1;
}

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	if (sz[u] > 1 && sz[v] > 1) return false;
	if (sz[u] < sz[v]) swap(u, v);
	p[v] = u;
	sz[u] += v;
	return true;
}

void dfs(int v, bool b) {
	ans[v] = b;
	visited[v] = true;
	for (const int u : g[v]) {
		if (visited[u]) continue;
		dfs(u, !b);
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	
	for (int i = 0; i < e; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges.push_back(make_pair(w, make_pair(u, v)));
	}
	
	for (int i = 1; i <= n; i++) make_set(i);
	sort(edges.begin(), edges.end());
	
	int mx = 0;
	for (int i = 0; i < (int) edges.size(); i++) {
		int u = edges[i].second.first, v = edges[i].second.second;
		int b = merge(u, v);
		if (b) {
			mx = max(mx, edges[i].first);
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	
	cout << mx << '\n';
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) dfs(i, 0);
		cout << (ans[i] ? 'B' : 'D');
	}
}
