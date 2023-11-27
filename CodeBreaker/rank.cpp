#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, n;
int visited[1005];
vector<int> g[1005], ans;

bool check(int v) {
	visited[v] = -1;
	for (int u : g[v]) {
		if (visited[u] == -1) return false;
		else if (visited[u] == 0 && !check(u)) return false;
	}
	visited[v] = 1;
	return true;
}

void dfs(int v) {
    visited[v] = true;
    for (int u : g[v]) if (!visited[u]) dfs(u);
    ans.push_back(v);
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> k >> n;
	for (int i = 0; i < n; i++) {
		string input; cin >> input;
		int a, b, c; char ch;
		stringstream ss(input);
		ss >> a >> ch >> b >> ch >> c;
		if (ch == ',') {
			g[a].push_back(b);
			g[a].push_back(c);
		} else {
			g[a].push_back(c);
			g[b].push_back(c);
		}
	}
	
	for (int i = 1; i <= k; i++) if (!visited[i] && !check(i)) {
		cout << 0;
		return 0;
	}

	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= k; i++) if (!visited[i]) dfs(i);
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < k; i++) cout << ans[i] << ' ';
}
