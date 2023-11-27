#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, depth[1000005];
bool visited[1000005];
vector<int> g[1000005];

void dfs(int v) {
	visited[v] = true;
	for (const int &u : g[v]) if (!visited[u]) {
		depth[u] = depth[v] + 1;
		dfs(u);
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a; cin >> a;
		g[a].push_back(i);
	}
	
	depth[0] = 1;
	dfs(0);
	cout << *max_element(depth, depth + n);
}
