#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int r, c, d, k; cin >> r >> c >> d >> k;
	bool g[r+1][c+1]; memset(g, 0, sizeof(g));
	vector<pair<int, int>> m;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char ch; cin >> ch;
			if (ch == 'S') g[i][j] = 1;
			else if (ch == 'M') m.push_back(make_pair(i, j));
		}
	}
		
	int pre[r+1][c+1]; memset(pre, 0, sizeof(pre));
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + g[i][j];
			
	int ans = 0;
	for (const pair<int, int> p : m) {
		int x1 = max(p.first - d, 1), x2 = min(p.first + d, r), y1 = max(p.second - d, 1), y2 = min(p.second + d, c);
		if (pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1] >= k) ans++;
	}
	
	cout << ans;
}
