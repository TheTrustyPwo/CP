#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, p[300005], m[300005], parent[300005];

void make_set(int v) {
	parent[v] = v;
}

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	parent[v] = u;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
		ans += m[i];
	}
	
	for (int i = 0; i < n; i++) make_set(i);
	for (int i = 0; i < n; i++) {
		if (i == p[i]) continue;
		merge(i, p[i]);
		ans -= m[i];
	}
	
	cout << ans;
}
