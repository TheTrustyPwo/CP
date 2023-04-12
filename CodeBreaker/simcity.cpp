#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dsu[300005];
int n, m;

int find(int n) {
	if (dsu[n] == n) return n;
	return dsu[n] = find(dsu[n]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;
	dsu[b] = a;
	return true;
}

struct Edge {
	ll from, to, value;
} e[600005];

bool cmp(Edge x, Edge y) {
	return x.value < y.value;
}

int d[300005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int total = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> d[i];
	n++;
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = 1; i <= m; i++) {
		total++;
		cin >> e[total].from >> e[total].to >> e[total].value;
		e[total].from++;
		e[total].to++;
	}
	for (int i = 1; i < n; i++) {
		e[++total].from = i;
		e[total].to = n;
		e[total].value = d[i];
	}
	sort(e + 1, e + total + 1, cmp);
	ll ans = 0, cnt = 0;
	for (int i = 1; i <= total; i++) {
		if (merge(e[i].from, e[i].to)) {
			cnt++;
			ans += e[i].value;
			if (cnt >= n - 1) {
				cout << ans;
				return 0;
			}
		}
	}
}
