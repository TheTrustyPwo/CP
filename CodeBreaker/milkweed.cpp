#include <bits/stdc++.h>

using namespace std;

int dir[8][2] = {
	{-1, 0}, // Up
	{1, 0}, // Down
	{0, -1}, // Left
	{0, 1}, // Right
	{-1, -1}, // Up Left
	{-1, 1}, // Up Right
	{1, -1}, // Down Left
	{1, 1}, // Down Right
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int X, Y, Mx, My;
	cin >> X >> Y >> Mx >> My;
	int ans = 0;
	char c;
	bool grid[105][105], visited[105][105];
	queue<pair<pair<int, int>, int>> q;
	
	for (int i = Y; i; i--) {
		for (int j = 1; j <= X; j++) {
			cin >> c;
			if (c == '.') grid[i][j] = 1;
		}
	}
	
	q.push(make_pair(make_pair(My, Mx), 0));
	visited[My][Mx] = true;
	grid[My][Mx] = 0;
	
	while (!q.empty()) {
		int xx = q.front().first.first, yy = q.front().first.second, t = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = xx + dir[i][0], ny = yy + dir[i][1];
			if (visited[nx][ny] || grid[nx][ny] != 1) continue;
			q.push(make_pair(make_pair(nx, ny), t + 1));
			grid[nx][ny] = 0;
			ans = max(ans, t + 1);
		}
	}
	
	cout << ans;
}
