#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
unordered_map<int, unordered_map<int, int>> mp;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, r, c; cin >> n >> m >> r >> c;
	pair<int, int> a[n]; for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	pair<int, int> b[m]; for (int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
	
	queue<pair<pair<int, int>, int>> q;
	while (!q.empty()) {
		int xx = q.front().first.first, yy = q.front().first.second, d = q.front().second;
		for (int i = 0; i < 4; i++) {
			int nx = xx + dr[i][0], ny = dr[i][1];
			if (nx > r || nx < 1 || ny > c || ny < 1 || mp[nx][ny]) continue;
			mp[nx][ny] = 1;
		}
	}
} 
