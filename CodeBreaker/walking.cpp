#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, l, ans = 1, parent[505], sz[505];
pair<int, int> a[505];

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (sz[u] < sz[v]) swap(u, v);
	parent[v] = u;
	sz[u] += v;
	ans = max(ans, sz[u]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> l >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	
	for (int i = 0; i < n; i++) parent[i] = i, sz[i] = 1;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		if ((((double) l) / ((double) a[i].second) + a[i].first) > (((double) l) / ((double) a[j].second) + a[j].first)) {
			merge(i, j);
			cout << i << ' ' << j << '\n';
		}
	}
	
	cout << ans;
}
