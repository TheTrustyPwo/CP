#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int g[n][n], dist[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			dist[i][j] = g[i][j];
		}
	}
	
	for (int mid = 0; mid < n; mid++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (u == v || u == mid || mid == v) continue;
				if (dist[u][v] < min(dist[u][mid], dist[mid][v]))
					dist[u][v] = min(dist[u][mid], dist[mid][v]);
			}
		}
	}
	
	int ans = 1000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else if (dist[i][j] == 0) {
				cout << 0;
				return 0;
			} else ans = min(ans, dist[i][j]);
		}
	}
	
	cout << ans;
}
