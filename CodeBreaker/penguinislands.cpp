#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, e;
int parent[205], sz[205];
pair<pair<int, int>, int> edges[40005];

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

bool check() {
	return (find(1) == find(2) && find(1) == find(3) && find(1) && find(4));
}

bool cmp(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2) {
	return p1.second < p2.second;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
	}
	
	sort(edges, edges + e, &cmp);
	
	int ans = 0;
	for (int i = 1; i <= n; i++) make_set(i);
	for (int i = 0; i < e; i++) {
		merge(edges[i].first.first, edges[i].first.second);
		ans += edges[i].second;
		if (check()) break;
	}
	
	cout << ans;
}
