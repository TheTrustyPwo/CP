#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int dir[2][2] = {{1, 0}, {0, 1}};

void test_case(int test) {
    int n; cin >> n;
    int g[2][n], dp[2][n];
    for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) {
        cin >> g[i][j];
        dp[i][j] = 0;
    }
    dp[0][0] = 1;

    queue<pair<int, int>> q; q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        int mn = 2;
        for (int i = 0; i < 2; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= n || ny >= 2) continue;
            mn = min(mn, g[nx][ny]);
        }
        for (int i = 0; i < 2; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= n || ny >= 2 || g[nx][ny] > mn) continue;
            q.push(make_pair(nx, ny));
            dp[nx][ny] += dp[x][y];
        }
    }

    cout << dp[1][n - 1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
