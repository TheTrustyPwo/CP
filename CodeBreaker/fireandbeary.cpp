#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int r, c; cin >> r >> c;
	pair<int, int> f, b;
	char g[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'F') f = make_pair(i, j);
			else if (g[i][j] == 'B') b = make_pair(i, j);
		}
	}
	
	if (abs(f.first - b.first) + abs(f.second - b.second) < 2) { cout << -1; return 0; }
	
	queue<pair<pair<int, int>, int>> q; q.push(make_pair(b, 2));
	bool valid[r][c]{}; valid[b.first][b.second] = 1;
	while (!q.empty()) {
		int xx = q.front().first.first, yy = q.front().first.second, d = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dir[i][0], ny = yy + dir[i][1];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || valid[nx][ny] || g[nx][ny] == '@' || (abs(f.first - nx) + abs(f.second - ny)) < d + 2) continue;
			valid[nx][ny] = 1;
			q.push(make_pair(make_pair(nx, ny), d + 2));
		}
	}
	
	
	q.push(make_pair(b, 2)); valid[b.first][b.second] = 0;
	while (!q.empty()) {
		int xx = q.front().first.first, yy = q.front().first.second, d = q.front().second; q.pop();
		if (xx == 0 || xx == r - 1 || yy == 0 || yy == c - 1) { cout << d; return 0; }
		for (int i = 0; i < 4; i++) {
			int nx = xx + dir[i][0], ny = yy + dir[i][1];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || !valid[nx][ny]) continue;
			valid[nx][ny] = 0;
			q.push(make_pair(make_pair(nx, ny), d + 2));
		}
	}
	
	cout << -1;
}
