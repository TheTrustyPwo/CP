#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
int parent[100005];
bool charge[100005];
vector<int> lst[100005];

void make_set(int v) {
	parent[v] = v;
	lst[v] = vector<int>(1, v);
}

int find(int v) {
	return parent[v];
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (lst[u].size() < lst[v].size()) swap(u, v);
	while (!lst[v].empty()) {
		int b = lst[v].back();
		lst[v].pop_back();
		parent[b] = u;
		lst[u].push_back(b);
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) make_set(i);
	while (q--) {
		char ch; int x, y; cin >> ch >> x >> y;
		if (ch == 'A') {
			if (find(x) == find(y)) continue;
			if (charge[x] == charge[y]) {
				x = find(x), y = find(y);
				if (lst[x].size() < lst[y].size()) swap(x, y);
				for (const int v : lst[y]) charge[v] = !charge[v];
			}
			merge(x, y);
		} else if (ch == 'R') {
			if (find(x) == find(y)) continue;
			if (charge[x] != charge[y]) {
				x = find(x), y = find(y);
				if (lst[x].size() < lst[y].size()) swap(x, y);
				for (const int v : lst[y]) charge[v] = !charge[v];
			}
			merge(x, y);
		} else {
			if (find(x) != find(y)) cout << "?\n";
			else if (charge[x] == charge[y]) cout << "R\n";
			else cout << "A\n";
		}
	}
}
