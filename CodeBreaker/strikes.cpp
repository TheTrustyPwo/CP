#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, deg[500005];
vector<int> g[500005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++, deg[b]++;
	}
	
	cin >> m; int ans = 1;
	while (m--) {
		int x; cin >> x;
		if (x > 0) {
			ans += deg[x] - 1;
			deg[x]--;
			for (const int u : g[x]) deg[u]--;
		} else {
			ans -= g[x].size() + 1;
			deg[x] = g[x].size();
			for (const int u : g[x]) deg[u]++;
		}
		cout << ans << '\n';
	}
}
