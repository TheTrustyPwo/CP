#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[500005], dsu[500005], sz[500005];
bool ok[500005];
int ans = 0;

void make_set(int v) {
	dsu[v] = v;
	sz[v] = 1;
}

int find(int v) {
	if (dsu[v] == v) return v;
	return dsu[v] = find(dsu[v]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (sz[u] < sz[v]) swap(u, v);
	dsu[v] = u;
	ans -= ((sz[u] + 1) / 2 + (sz[v] + 1) / 2);
	sz[u] += sz[v];
	ans += ((sz[u] + 1) / 2);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= 500000; i++) make_set(i);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (!ok[x]) ok[x] = 1, ans++;
		if (ok[x - 1]) merge(x, x - 1);
		if (ok[x + 1]) merge(x, x + 1);
		cout << ans << ' ';
	}
}
