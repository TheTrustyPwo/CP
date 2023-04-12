#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005, LOG = 18;

struct Edge {
    int u, v, weight;
    Edge (int _u, int _v, int _weight): u(_u), v(_v), weight(_weight) {}
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n, e, q, parent[MAXN], ranks[MAXN], depth[MAXN], up[MAXN][LOG], mx[MAXN][LOG];
vector<Edge> edges;
vector<pair<int, int>> result[MAXN];

void make_set(int v) {
	parent[v] = v;
	ranks[v] = 0;
}

int find(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		if (ranks[a] < ranks[b]) swap(a, b);
		parent[b] = a;
		if (ranks[a] == ranks[b]) ranks[a]++;
	}
}

void dfs(int v, int p, int w) {
	up[v][0] = p; mx[v][0] = w;
	if (v != 0) depth[v] = depth[p] + 1;
	for (int i = 1; i < LOG; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		mx[v][i] = max(mx[v][i - 1], mx[up[v][i - 1]][i - 1]);
	}
	for (const pair<int, int> u : result[v])
		if (u.first != p) dfs(u.first, v, u.second);
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int ans = 0, diff = depth[a] - depth[b];
	
	while (diff) {
		int lg = log2(diff);
		ans = max(ans, mx[a][lg]);
		a = up[a][lg];
		diff -= (1 << lg);
	}
	
	while (a != b) {
		int lg = log2(depth[a]);
		while (lg && up[a][lg] == up[b][lg]) lg--;
		ans = max(ans, max(mx[a][lg], mx[b][lg]));
		a = up[a][lg], b = up[b][lg];
	}
	
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e >> q;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back(Edge(a, b, c));
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) make_set(i);
	sort(edges.begin(), edges.end());
	for (Edge e : edges) {
		if (cnt == n - 1) break;
		if (find(e.u) != find(e.v)) {
			result[e.u].push_back(make_pair(e.v, e.weight));
			result[e.v].push_back(make_pair(e.u, e.weight));
			merge(e.u, e.v);
			cnt++;
		}
	}
	
	dfs(0, 0, 0);
	
	while (q--) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}
