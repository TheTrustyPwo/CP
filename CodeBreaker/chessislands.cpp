#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 50005;

int n, e, a[MAXN], ans = 0;
bool visited[MAXN];
vector<int> g[MAXN];

void bfs(int root) {
	if (visited[root]) return;
	int ans1 = 0, ans2 = 0;
	queue<pair<int, int>> q; q.push(make_pair(root, 0));
	visited[root] = 1;
	while (!q.empty()) {
		int nx = q.front().first, d = q.front().second; q.pop();
		if (d & 1) ans1 += a[nx];
		else ans2 += a[nx];
		for (const int u : g[nx]) {
			if (visited[u]) continue;
			visited[u] = 1;
			q.push(make_pair(u, d + 1));
		}
	}
	ans += min(ans1, ans2);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < e; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) bfs(i);
	
	cout << ans;
}
