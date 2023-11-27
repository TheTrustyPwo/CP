#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
pair<int, int> edges[100005];
int parent[100005], sz[100005], ans[100005];

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
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> edges[i].first >> edges[i].second;
	
	for (int i = 1; i <= n; i++) make_set(i);
	
	int cur = n * (n - 1) / 2; ans[m - 1] = cur;
	for (int i = m - 1; i > 0; i--) {
		int u = find(edges[i].first), v = find(edges[i].second);
		if (u != v) cur -= (sz[u] * sz[v]);
		ans[i - 1] = cur;
		merge(u, v);
	}
	
	for (int i = 0; i < m; i++) cout << ans[i] << '\n';
}
