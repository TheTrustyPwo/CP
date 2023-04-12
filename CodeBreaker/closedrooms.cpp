#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int h, w, k; cin >> h >> w >> k;
	pair<int, int> start;
	char g[h][w];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'S') start = make_pair(i, j);
		}
	}

	int ans = 1e9;
	queue<pair<pair<int, int>, int>> q; q.push(make_pair(start, 0));
	bool visited[h][w]{}; visited[start.first][start.second] = 1;
	while (!q.empty()) {
		int xx = q.front().first.first, yy = q.front().first.second, d = q.front().second; q.pop();
		int m = min(min(xx, yy), min(h - xx - 1, w - yy - 1));
		ans = min(ans, (m / k) + (m % k != 0) + 1);
		for (int i = 0; i < 4; i++) {
			int nx = xx + dir[i][0], ny = yy + dir[i][1];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny] || g[nx][ny] == '#' || d >= k) continue;
			visited[nx][ny] = 1;
			q.push(make_pair(make_pair(nx, ny), d + 1));
		}
	}
	
	cout << ans;
}
