#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 100005;

int l, n, g[26][26], dist[26][26], mn[26][26];
string s;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> l >> n >> s;
	for (int i = 0; i < 26; i++) fill(g[i], g[i] + 26, 1e18), fill(dist[i], dist[i] + 26, 1e18);
	for (int i = 0; i < n; i++) {
		char a, b; int c; cin >> a >> b >> c;
		int x = a - 'a', y = b - 'a';
		g[x][y] = min(g[x][y], c);
		dist[x][y] = g[x][y];
	}
	
	for (int i = 0; i < 26; i++) dist[i][i] = 0;
	
	for (int mid = 0; mid < 26; mid++) {
		for (int u = 0; u < 26; u++) {
			for (int v = 0; v < 26; v++) {
				if (u == v || u == mid || mid == v) continue;
				if (dist[u][v] > dist[u][mid] + dist[mid][v])
					dist[u][v] = dist[u][mid] + dist[mid][v];
			}
		}
	}
	
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			int res = 1e18;
			for (int k = 0; k < 26; k++)
				res = min(res, dist[i][k] + dist[j][k]);
			mn[i][j] = res;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < l / 2; i++) {
		int x = s[i] - 'a', y = s[l - i - 1] - 'a';
		int cost = mn[x][y];
		if (cost == 1e18) { cout << -1; return 0; }
		ans += cost;
	}
	
	cout << ans;
}
