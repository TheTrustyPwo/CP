#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[100005], color[100005], take = 0;
vector<pair<int, int>> g[100005];
bool visited[100005], amos = true;

void dfs(int v, int col) {
	visited[v] = true;
	color[v] = col;
	take++;
	for (const auto it : g[v]) {
		if (visited[it.first]) {
			if ((color[it.first] ^ it.second) != color[v])
				amos = false;
		} else {
			dfs(it.first, col ^ it.second);
		}
	}
	
	if (p[v] == 0) amos = false;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i <= n; i++) g[i].clear();
	memset(visited, 0, sizeof(visited));
	
	for (int i = 0; i <= n; i++) p[i] = i;
	
	char tp; int a, b;
	for (int i = 0; i < m; i++) {
		cin >> tp;
		if (tp == '+') {
			cin >> a >> b;
			p[a] = p[b];
		} else if (tp == '-') {
			cin >> a >> b;
			p[a] = -p[b];
		} else {
			cin >> a;
			if (tp == 'T') p[a] = n + 1;
			else if (tp == 'F') p[a] = -(n + 1);
			else p[a] = 0;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (abs(p[i]) == n + 1 || p[i] == 0) continue;
		if (p[i] > 0) {
			g[p[i]].push_back({i, 0});
			g[i].push_back({p[i], 0});
		} else {
			g[-p[i]].push_back({i, 1});
			g[i].push_back({-p[i], 1});
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		take = 0, amos = true;
		dfs(i, 0);
		if (!amos) cnt += take;
	}
	
	cout << cnt << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
	int c, t; cin >> c >> t;
	while (t--) {
		solve();
	}
}
