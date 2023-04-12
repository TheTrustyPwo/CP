#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dir[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int m, n, s, ans = 0; cin >> m >> n >> s;
	pair<int, int> a[s];
	for (int i = 0; i < s; i++) {
		int x, y; cin >> x >> y;
		a[i] = make_pair(--x, --y);
	}
	
	bool visited[m][n]{};
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < s; i++) {
		visited[a[i].first][a[i].second] = true;
		q.push(make_pair(a[i], 1));
	}
	
	while (!q.empty()) {
		int xx = q.front().first.first, yy = q.front().first.second, d = q.front().second;
		ans = d;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = xx + dir[i][0], ny = yy + dir[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push(make_pair(make_pair(nx, ny), d + 1));
		}
	}
	
	cout << ans;
}
