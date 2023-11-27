#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int dir1[2][2] = {{1, 0}, {-1, 0}};
const int dir2[2][2] = {{0, 1}, {0, -1}};

int r, c;
int cc[1005][1005];
bool g[1005][1005], visited[1005][1005];

void bfs(int y, int x, int z) {
	visited[y][x] = 1;
	queue<pair<int, int>> q; q.push(make_pair(y, x));
	while (!q.empty()) {
		pair<int, int> u = q.front(); q.pop();
		cc[u.first][u.second] = z;
		const int (*dir)[2] = (g[u.first][u.second] ? dir1 : dir2);
		for (int i = 0; i < 2; i++) {
			int nx = u.second + dir[i][0], ny = u.first + dir[i][1];
			if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> g[i][j];
	
	memset(visited, 0, sizeof(visited));
	
	int cnt = 1;
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (!visited[i][j]) {
		bfs(i, j, cnt);
		cnt++;
	}
	
	int d[cnt]; fill(d, d + cnt, 0);
	set<int> gg[cnt];
	
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
		int c1 = cc[i][j], c2 = cc[i][min(j + 1, c - 1)], c3 = cc[min(i + 1, r - 1)][j];
		if (j < c - 1 && c1 != c2) {
			gg[c1].insert(c2);
			gg[c2].insert(c1);
		}
		if (i < r - 1 && c1 != c3) {
			gg[c1].insert(c3);
			gg[c3].insert(c1);
		}
	}
	
	d[1] = 0;
	queue<int> q; q.push(1);
	bool vis[cnt]{}; vis[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (const int &v : gg[u]) {
			if (vis[v]) continue;
			vis[v] = 1;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	
	cout << d[cc[r - 1][c - 1]];
}
