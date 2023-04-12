#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3F3F3F3F;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, e, q; cin >> n >> e >> q;
	ll adj[n][n], dist[n][n];
	memset(adj, inf, sizeof(adj));
	while (e--) {
		ll a, b, w; cin >> a >> b >> w;
		adj[a][b] = w;
		adj[b][a] = w;
	}
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			dist[i][j] = adj[i][j];
	for (ll mid = 0; mid < n; mid++)
		for (ll u = 0; u < n; u++)
			for (ll v = 0; v < n; v++) {
				if (u == v || u == mid || v == mid) continue;
				if (dist[u][mid] + dist[mid][v] < dist[u][v])
					dist[u][v] = dist[u][mid] + dist[mid][v];
			}
	while (q--) {
		ll a, b; cin >> a >> b;
		cout << (a == b ? 0 : (dist[a][b] == 4557430888798830399 ? -1 : dist[a][b])) << endl;
	}
}
