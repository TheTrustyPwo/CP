#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e, tc;
int parent[50005], sz[50005];
bool ans[100005];
vector<vector<int>> edges, queries;

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

bool cmp1(vector<int> &v1, vector<int> &v2) {
	return v1[2] < v2[2];
}

bool cmp2(vector<int> &v1, vector<int> &v2) {
	return v1[3] > v2[3];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v, o, c; cin >> u >> v >> o >> c;
		edges.push_back({u, v, o, c});
	}
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int u, v, t; cin >> u >> v >> t;
		queries.push_back({u, v, t, i});
	}
	
	sort(edges.begin(), edges.end(), &cmp1);
	sort(queries.begin(), queries.end(), &cmp1);

	int pos = 0, cut = 0;
	for (int i = 0; i < n; i++) make_set(i);
	for (int i = 0; i < tc; i++) {
		if (queries[i][2] > edges[e - 1][2]) { cut = i; break; }
		for (; pos < e && edges[pos][2] <= queries[i][2]; pos++)
			merge(edges[pos][0], edges[pos][1]);
		ans[queries[i][3]] = find(queries[i][0]) == find(queries[i][1]);
	}
	
	pos = 0;
	sort(edges.begin(), edges.end(), &cmp2);
	for (int i = 0; i < n; i++) make_set(i);
	for (int i = tc - 1; i >= cut; i--) {
		for (; pos < e && edges[pos][3] >= queries[i][2]; pos++)
			merge(edges[pos][0], edges[pos][1]);
		ans[queries[i][3]] = find(queries[i][0]) == find(queries[i][1]);
	}
	
	for (int i = 0; i < tc; i++) cout << (ans[i] ? 'Y' : 'N') << '\n';
}
