#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

void test_case(int test) {
    int k, n, m; cin >> k >> n >> m;
    char g[k][n][m];
    int startx, starty;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int a = 0; a < m; a++)
                cin >> g[i][j][a];
        }
    }
    cin >> startx >> starty; startx--; starty--;

    bool visited[k][n][m]{}; visited[0][startx][starty] = 1;
    queue<pair<pair<int, int>, int>> q; q.push({{0, startx}, starty});
    while (!q.empty()) {
        int xx = q.front().first.first, yy = q.front().first.second, zz = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = xx + dir[i][0], ny = yy + dir[i][1], nz = zz + dir[i][2];
            if (nx < 0 || nx >= k || ny < 0 || ny >= n || nz < 0 || nz >= m || visited[nx][ny][nz]) continue;
            if (g[nx][ny][nz] == '#') continue;
            visited[nx][ny][nz] = 1;
            q.push({{nx, ny}, nz});
        }
    }

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int a = 0; a < m; a++)
                cnt += visited[i][j][a];
        }
    }

    cout << cnt;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
