#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int h, w, x, y, k; cin >> h >> w >> x >> y >> k;
	bool grid[h][w], visited[h][w]{};
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> grid[i][j];
			
	
			
	queue<pair<pair<int, int>, int>> q;
	visited[x][y] = 1; q.push(make_pair(make_pair(x, y), 1));
	int total = 0, cur = 0, time = 0;
	while (time <= k) {
		if (q.empty()) {
			cur = total - cur;
			if (time > 0) cout << cur << endl;
			if (cur == 0) total = 0;
			time++;
			continue;
		}
		
		int xx = q.front().first.first, yy = q.front().first.second, t = q.front().second; q.pop();
		if (t > time + 1) {
			cur = total - cur;
			if (time > 0) cout << cur << endl;
			time++;
		}
		
		total++;
		for (int i = 0; i < 4; i++) {
			int nx = xx + dir[i][0], ny = yy + dir[i][1];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny] || grid[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push(make_pair(make_pair(nx, ny), t + 1));
		}
	}
}
