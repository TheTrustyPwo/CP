#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
} edges[300005];

vector<int> parent(300005, 0), sz(300005, 0);

void make_set(int v) {
    parent[v] = v;
    sz[v] = 0;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        if (sz[a] == sz[b])
            sz[a]++;
    }
}

int n, m;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	
	int mx = 1e9;
	for (int i = 1; i <= n; i++) make_set(i);
	sort(edges, edges + m);
	for (int i = m - 1; i >= 0; i--) {
		Edge e = edges[i];
		if (find_set(e.u) != find_set(e.v)) {
			mx = min(mx, e.w);
			union_sets(e.u, e.v);
		}
	}
	
	int cost = 0;
	for (int i = 1; i <= n; i++) make_set(i);
	for (int i = 0; i < m; i++) {
		Edge e = edges[i];
		if (e.w < mx) continue;
		if (find_set(e.u) != find_set(e.v)) {
			cost += e.w;
			union_sets(e.u, e.v);
		}
	}
	
	cout << cost;
}
