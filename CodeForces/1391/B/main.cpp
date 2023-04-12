#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m; cin >> n >> m;
    char g[n][m]; int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    for (int i = 0; i < n - 1; i++)
        if (g[i][m - 1] == 'R') cnt++;
    for (int i = 0; i < m - 1; i++)
        if (g[n - 1][i] == 'D') cnt++;
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
