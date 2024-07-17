#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, l;
vector<int> g[200005];
pair<int, int> a[200005];
pair<int, int> lca[200005];
int t = 1;
int depth[200005], tin[200005], tout[200005];
int up[200005][20];
<<<<<<< Updated upstream
int ft[200005];
bool chosen[200005];

void update(int l, int r, int v) {
    while (l <= n){
        ft[l] += v;
        l += l & -l;
    }
    r++;
    while (r <= n) {
		ft[r] -= v;
		r += r & -r;
	}
}

int query(int x){
    int res = 0;
    while (x){
        res += ft[x];
        x -= x & -x;
    }
    return res;
}


=======
bool chosen[200005];

>>>>>>> Stashed changes
void dfs(int v, int p) {
	tin[v] = t++;
	up[v][0] = p;
	for (int i = 1; i <= l; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
		
	for (const int u : g[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		dfs(u, v);
	}
	
<<<<<<< Updated upstream
	tout[v] = t - 1;
=======
	tout[v] = t++;
}

int par[2005];

void dfs2(int v, int p) {
	par[v] = p;
	for (const int u : g[v]) 
		if (u != p) dfs2(u, v);
>>>>>>> Stashed changes
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	l = ceil(log2(n));
<<<<<<< Updated upstream
	// for (int i = 0; i <= 200000; i++) for (int j = 0; j < 20; j++) up[i][j] = 1;
=======
>>>>>>> Stashed changes
	depth[1] = 1;
	dfs(1, 1);
	
	for (int i = 0; i < m; i++) {
<<<<<<< Updated upstream
		int u, v; cin >> u >> v;
=======
		int u, v; cin >> u >> v; int tmp = u;
>>>>>>> Stashed changes
		a[i] = {u, v};
		if (is_ancestor(u, v)) { lca[i] = {u, i}; continue; }
		if (is_ancestor(v, u)) { lca[i] = {v, i}; continue; }
		for (int i = l; i >= 0; i--)
<<<<<<< Updated upstream
			if (!is_ancestor(up[u][i], v))
				u = up[u][i];
		lca[i] = {up[u][0], i};
	}

	int ans = 0;
	sort(lca, lca + m, [](pair<int, int> a, pair<int, int> b) { return depth[a.first] > depth[a.second]; });
	for (int i = 0; i < m; i++) {
		int u = a[lca[i].second].first, v = a[lca[i].second].second;
		bool b = chosen[lca[i].first] ||
				 query(tin[u]) > query(tin[lca[i].first]) ||
				 query(tin[v]) > query(tin[lca[i].first]);
		if (!b) {
			chosen[lca[i].first] = 1;
			update(tin[lca[i].first], tout[lca[i].first], 1);
			ans++;
		}
=======
			if (!is_ancestor(up[tmp][i], v))
				tmp = up[tmp][i];
		lca[i] = {up[tmp][0], i};
	}

	sort(lca, lca + m, [](pair<int, int> a, pair<int, int> b) { return depth[a.first] > depth[a.second]; });
	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool b = true;
		int u = a[lca[i].second].first, v = a[lca[i].second].second;
		dfs2(u, -1);
		while (v != -1) {
			if (chosen[v]) { b = false; break; }
			v = par[v];
		}
		if (b) chosen[lca[i].first] = 1, ans++;
>>>>>>> Stashed changes
	}
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) if (chosen[i]) cout << i << ' ';
}
