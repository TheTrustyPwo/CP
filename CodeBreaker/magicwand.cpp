#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	int H, W, X, Y, T, N;
	cin >> H >> W >> X >> Y >> T;
	int grid[H][W];
	queue<pair<int, int>> q;
	
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> grid[i][j];
	
	X -= 1;
	Y -= 1;
	
	q.push(make_pair(X, Y));
	N = grid[X][Y];
	grid[X][Y] = 0x3F3F3F3F;
	
	while (!q.empty()) {
		int xx = q.front().first, yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dir[i][0], ny = yy + dir[i][1];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (abs(grid[nx][ny] - N) > T) continue;
			q.push(make_pair(nx, ny));
			grid[nx][ny] = 0x3F3F3F3F;
		}
	}
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cout << (grid[i][j] == 0x3F3F3F3F ? '1' : '0');
		cout << endl;
	}
}
