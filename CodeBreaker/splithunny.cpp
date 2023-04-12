#include <bits/stdc++.h>
using namespace std;
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
const int dir1[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dir2[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	setup();
	char a;
	int r, c;
	cin >> r >> c;
	bool grid[r][c]{}, visited[r][c]{};
	range(i, 0, r) {
		range(j, 0, c) {
			cin >> a;
			if (a == 'H') grid[i][j] = 1;
		}
	}
	
	int ans = 0;
	range(i, 0, r) {
		range(j, 0, c) {
			if (!grid[i][j] || visited[i][j]) continue;
			queue<pair<int, int>> q;
			q.emplace(i, j);
			while (!q.empty()) {
				int xx = q.front().first, yy = q.front().second;
				q.pop();
				range(k, 0, 4) {
					int nx = xx + dir1[k][0], ny = yy + dir1[k][1];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if (!grid[nx][ny] || visited[nx][ny]) continue;
					visited[nx][ny] = true;
					q.emplace(nx, ny);
				}
			}
			ans++;
		}
	}
	
	cout << "Oh, bother. There are " << ans << " pools of hunny.";
}
