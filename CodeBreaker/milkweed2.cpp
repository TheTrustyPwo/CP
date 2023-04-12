#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define revrange(it, start, end) for (int it = start; it > end; it--)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int dir1[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dir2[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	setup();
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	swap(x, y); swap(a, b);
	bool grid[x][y]{}, visited[x][y]{};
	queue<pair<pair<int, int>, int>> q;
	
	range(i, 0, x) {
		string s;
		cin >> s;
		range(j, 0, y) {
			grid[i][j] = s[j] == '.';
		}
	}
	
	q.push(make_pair(make_pair(x - a, b - 1), 0));
	visited[x - a][b - 1] = true;
	
	int ans = 0;
	while (!q.empty()) {
		int xx = q.front().first.first, yy = q.front().first.second, t = q.front().second;
		q.pop();
		ans = t;
		range(i, 0, 8) {
			int nx = xx + dir2[i][0], ny = yy + dir2[i][1];
			if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
			if (visited[nx][ny] || !grid[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push(make_pair(make_pair(nx, ny), t + 1));
		}
	}
	
	cout << ans;
}
