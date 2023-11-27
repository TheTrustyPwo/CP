#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m; cin >> n >> m;
    char g[n][m], ans[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> g[i][j];

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans[i][j] = '.';

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'U') {
                ans[i][j] = (cnt & 1 ? 'B' : 'W');
                ans[i + 1][j] = (cnt & 1 ? 'W' : 'B');
                cnt++;
            }
        if (cnt & 1) { cout << -1 << '\n'; return; }
    }

    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (g[j][i] == 'L') {
                ans[j][i] = (cnt & 1 ? 'B' : 'W');
                ans[j][i + 1] = (cnt & 1 ? 'W' : 'B');
                cnt++;
            }
        if (cnt & 1) { cout << -1 << '\n'; return; }
    }

    for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cout << ans[i][j]; cout << '\n'; }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
