#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, parent[2][100005], sz[2][100005];

void make_set(int v) {
	parent[0][v] = parent[1][v] = v;
	sz[0][v] = sz[1][v] = 1;
}

int find(int v, int j) {
	if (parent[j][v] == v) return v;
	return parent[j][v] = find(parent[j][v], j);
}

void merge(int a, int b, int j) {
	a = find(a, j), b = find(b, j);
	if (a == b) return;
	if (sz[j][a] < sz[j][b]) swap(a, b);
	parent[j][b] = a;
	sz[j][a] += sz[j][b];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n; for (int i = 1; i <= n; i++) make_set(i);
	for (int i = 1; i < n; i++) {
		int u, v, j; cin >> u >> v >> j;
		merge(u, v, j);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[0][i] == i) ans += sz[0][i] * (sz[0][i] - 1);
		if (parent[1][i] == i) ans += sz[1][i] * (sz[1][i] - 1);
		ans += (sz[0][find(i, 0)] - 1) * (sz[1][find(i, 1)] - 1);
	} cout << ans;
}
