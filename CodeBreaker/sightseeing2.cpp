#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e, q, cost, mx = 1;
int parent[50005], mn[50005], sz[50005], ans[50005];
pair<int, int> queries[50005];
pair<pair<int, int>, int> edges[1000005];

bool cmp(pair<pair<int, int>, int> &e1, pair<pair<int, int>, int> &e2) {
	return e1.second > e2.second;
}

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
	mn[v] = 1e9;
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
	mx = max(mx, sz[u]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e >> q;
	for (int i = 0; i < e; i++) cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
	for (int i = 0; i < q; i++) { cin >> queries[i].first; queries[i].second = i; }
	
	sort(edges, edges + e, &cmp);
	sort(queries, queries + q);
	
	for (int i = 1; i <= n; i++) make_set(i);
	
	int pos = 0;
	for (int i = 0; i < q; i++) {
		for (; pos < e && mx < queries[i].first; pos++) {
			int u = edges[pos].first.first, v = edges[pos].first.second;
			merge(u, v);
			int new_mn = min(min(mn[u], mn[v]), edges[pos].second);
			mn[u] = new_mn, mn[v] = new_mn;
			cost = new_mn;
		}
		if (mx < queries[i].first) ans[queries[i].second] = -1;
		else ans[queries[i].second] = cost;
	}
	
	for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
