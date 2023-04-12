#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500005;

struct Edge {
    int u, v, weight;
    Edge (int _u, int _v, int _weight): u(_u), v(_v), weight(_weight) {}
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
};

int n, e, q, parent[MAXN], ranks[MAXN], quality[MAXN];
vector<Edge> edges;
vector<pair<int, int>> res[MAXN];

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

void dfs(int v, int p) {
	for (const pair<int, int> u : res[v]) {
		if (u.first == p) continue;
		quality[u.first] = min(quality[v], u.second);
		dfs(u.first, v);
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e >> q;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back(Edge(a, b, c));
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) make_set(i);
	sort(edges.begin(), edges.end());
	for (Edge e : edges) {
		if (cnt == n - 1) break;
		if (find(e.u) != find(e.v)) {
			res[e.u].push_back(make_pair(e.v, e.weight));
			res[e.v].push_back(make_pair(e.u, e.weight));
			merge(e.u, e.v);
			cnt++;
		}
	}
	
	quality[1] = 1e9;
	dfs(1, 1);
	
	while (q--) {
		int x; cin >> x;
		cout << quality[x] << "\n";
	}
}
