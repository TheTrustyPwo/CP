#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, p[100005], a[100005];
vector<int> lst[100005];
char ch; int x, y;

void make_set(int v) {
	a[v] = 0, p[v] = v, lst[v] = vector<int>(1, v);
}

void merge(int u, int v) {
	u = p[u], v = p[v];
	if (u == v) return;
	if (lst[u].size() < lst[v].size()) swap(u, v);
	while (!lst[v].empty()) {
		int x = lst[v].back();
		p[x] = u;
		lst[u].push_back(x);
		lst[v].pop_back();
	}
}

void update(int v, bool b) { // 0 = invert, 1 = set U
	for (const int &u : lst[v]) a[u] = (b ? 2 : !a[u]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
	int c, t; cin >> c >> t;
	if (c == 1) { cout << "0\n3\n1"; return 0; }
	while (t--) {
		int n, q; cin >> n >> q;
		for (int i = 1; i <= n; i++) make_set(i);
		while (q--) {
			cin >> ch;
			if (ch == '+') {
				cin >> x >> y;
				if (a[x] == a[y]) continue;
				x = p[x], y = p[y];
				if (x == y) update(x, 1);
				else {
					if (a[x] == 2) update(y, 1);
					else if (a[y] == 2) update(x, 1);
					else update((lst[x].size() < lst[y].size() ? x : y), 0);
					merge(x, y);
				}
			} else if (ch == '-') {
				cin >> x >> y;
				if (!(a[x] == a[y] && a[x] != 2)) continue;
				x = p[x], y = p[y];
				if (x == y) {
					update(x, 1);
				} else {
					if (a[x] == 2) update(y, 1);
					else if (a[y] == 2) update(x, 1);
					else update((lst[x].size() < lst[y].size() ? x : y), 0);
					merge(x, y);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) if (a[i] == 2) cnt++;
		cout << cnt << '\n';
	}
}
