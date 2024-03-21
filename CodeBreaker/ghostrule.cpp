#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x, k, d, depth[2005];
vector<int> g[2005];
bool h[2005], visited[2005];
bool acc[2005][2005];

void bfs(int start) {
	for (int i = 0; i <= n; i++) visited[i] = 0;
	queue<pair<int, int>> q;
	q.emplace(start, 0); visited[start] = 1;
	while (!q.empty()) {
		int u = q.front().first, dist = q.front().second; q.pop();
		if (h[u]) acc[start][u] = acc[u][start] = 1;
		if (dist >= x) continue;
		for (const int c : g[u]) {
			if (visited[c]) continue;
			visited[c] = 1;
			q.emplace(c, dist + 1);
		}
	}
}

vector<int> find(int start) {
	vector<int> vec;
	for (int i = 0; i <= n; i++) visited[i] = 0;
	queue<pair<int, int>> q;
	q.emplace(start, 0); visited[start] = 1;
	while (!q.empty()) {
		int u = q.front().first, dist = q.front().second; q.pop();
		if (h[u]) vec.push_back(u);
		if (dist >= x) continue;
		for (const int c : g[u]) {
			if (visited[c]) continue;
			visited[c] = 1;
			q.emplace(c, dist + 1);
		}
	}
	return vec;
}

void dfs(int v, int p) {
	for (const int u : g[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		dfs(u, v);
	}
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> x >> k >> d;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for (int i = 0; i < k; i++) {
		int z; cin >> z; h[z] = 1;
		acc[z][z] = 1;
	}
	
	for (int i = 0; i <= n; i++) if (h[i]) bfs(i);

	while (d--) {
		int u, v; cin >> u >> v;
		fill(depth, depth + n + 1, 1e9); depth[u] = 0; dfs(u, -1);
		vector<int> a = find(u), b = find(v);
		bool ans = 0;
		for (int s : a) for (int f : b) if (acc[s][f]) ans = 1;
		if (ans || depth[v] <= x) cout << "YES\n";
		else cout << "NO\n";
	}
}
