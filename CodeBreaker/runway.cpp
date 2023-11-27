#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Edge {
	int u, v, w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	bool operator <(Edge const &other) {
		return w < other.w;
	}
};

int n, e, k, parent[100005], sz[100005], d[100005];
pair<int, int> b[100005];
vector<pair<int, int>> g[100005], h[100005];
bool visited[100005];
queue<int> q;
vector<Edge> edges;

void dfs(int v) {
	visited[v] = true;
	for (const pair<int, int> u : h[v]) {
		if (visited[u.first]) continue;
		b[u.first] = make_pair(v, u.second);
		dfs(u.first);
	}
}

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
}

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (sz[u] < sz[v]) swap(u, v);
	parent[v] = u;
	sz[u] += sz[v];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e >> k;
	for (int i = 0; i < e; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
		edges.push_back(Edge(a, b, w));
	}
	
	q.push(1); visited[1] = true; d[1] = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (const pair<int, int> p : g[v]) {
			if (visited[p.first]) continue;
			visited[p.first] = true;
			d[p.first] = d[v] + 1;
			q.push(p.first);
		}
	}
	
	if (d[n] < k) {
		cout << -1;
		return 0;
	}
	
	for (int i = 1; i <= n; i++) make_set(i);
	
	sort(edges.begin(), edges.end());
	for (const Edge e : edges) {
		if (find(1) == find(n)) break;
		if (find(e.u) != find(e.v)) {
			h[e.u].push_back(make_pair(e.v, e.w));
			h[e.v].push_back(make_pair(e.u, e.w));
			merge(e.u, e.v);
		}
	}
	
	memset(visited, 0, sizeof(visited));
	dfs(1); b[1] = make_pair(-1, 0);
	
	vector<int> weights;
	pair<int, int> p = make_pair(n, 0);
	while (p.first != -1) {
		if (p.second > 0) weights.push_back(p.second);
		p = b[p.first];
	}
        
    sort(weights.begin(), weights.end(), greater<int>());
    cout << weights[k - 1];
}
