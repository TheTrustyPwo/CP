#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int r, c; cin >> r >> c;
	int p[r][c];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> p[i][j];
	
	int ans = p[0][0]; p[0][0] = 0;
	pair<int, int> cur = make_pair(0, 0);
	while (cur.first != r - 1 || cur.second != c - 1) {
		int mf = 0; pair<int, int> nc;
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + d[i][0], ny = cur.second + d[i][1], f = p[nx][ny];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || f == 0) continue;
			if (f > mf) {
				mf = f;
				nc = make_pair(nx, ny);
			}
		}
		p[nc.first][nc.second] = 0;
		ans += mf;
		cur = nc;
	}
	cout << ans;
}
