#include <bits/stdc++.h>
using namespace std;
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

bool visited[1000005];
vector<int> g[1000005];

void dfs(int source) {
	if (visited[source]) return;
	visited[source] = true;
	for (const int v : g[source]) dfs(v);
}

int32_t main() {
	setup();
	int n, e, ans = 0; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		dfs(i);
		ans++;
	}
	cout << ans;
}
