#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int r, c, k; cin >> r >> c >> k;
	char g[r][c]; pair<int, int> s, e;
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
		cin >> g[i][j];
		if (g[i][j] == 'S') s = make_pair(i, j);
		else if (g[i][j] == 'E') e = make_pair(i, j);
	}
	
	queue<pair
}
