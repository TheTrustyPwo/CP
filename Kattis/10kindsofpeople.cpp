#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int r, c;
bool grid[1005][1005], visited[1005][1005];
int bin[1005][1005], de[1005][1005];
queue<pair<int, int>> q;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char ch; cin >> ch;
			grid[i][j] = ch == '1';
		}
	}
	
	// Binary BFS
	int b = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] || visited[i][j]) continue;
			q.emplace(i, j); visited[i][j] = true;
			while (!q.empty()) {
				int xx = q.front().first, yy = q.front().second;
				bin[xx][yy] = b;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = xx + dir[i][0], ny = yy + dir[i][1];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if (grid[nx][ny] || visited[nx][ny]) continue;
					visited[nx][ny] = true;
					q.emplace(nx, ny);
				}
			}
			b++;
		}
	}
	
	memset(visited, 0, sizeof(visited));
	
	// Decimal BFS
	int d = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!grid[i][j] || visited[i][j]) continue;
			q.emplace(i, j); visited[i][j] = true;
			while (!q.empty()) {
				int xx = q.front().first, yy = q.front().second;
				de[xx][yy] = d;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = xx + dir[i][0], ny = yy + dir[i][1];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if (!grid[nx][ny] || visited[nx][ny]) continue;
					visited[nx][ny] = true;
					q.emplace(nx, ny);
				}
			}
			d++;
		}
	}
	
	int m; cin >> m;
	while (m--) {
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; r1--; c1--; r2--; c2--;
		if (bin[r1][c1] == bin[r2][c2] && bin[r1][c1] != 0 && bin[r2][c2] != 0) cout << "binary\n";
		else if (de[r1][c1] == de[r2][c2] && de[r1][c1] != 0 && de[r2][c2] != 0) cout << "decimal\n";
		else cout << "neither\n";
	}
}
