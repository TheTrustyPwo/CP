#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int32_t main() {
	setup();
	int h, w; cin >> h >> w;
	int g[h][w], a[h][w];
	range(i, 0, h)
		range(j, 0, w) {
			int e; cin >> e;
			g[i][j] = e;
		}
	range(i, 0, w) a[0][i] = g[0][i];
	range(i, 1, h)
		range(j, 0, w)
			a[i][j] = g[i][j] + max(a[i-1][max(0, j-1)], max(a[i-1][j], a[i-1][min(w-1,j+1)]));
	int ans = 0;
	range(i, 0, w) ans = max(ans, a[h-1][i]);
	cout << ans;
}
