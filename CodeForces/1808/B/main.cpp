#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, m; cin >> n >> m;
    int a[m][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[j][i];

    for (int i = 0; i < m; i++) sort(a[i], a[i] + n);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int pre[n]; pre[0] = a[i][0];
        for (int j = 1; j < n; j++) pre[j] = pre[j - 1] + a[i][j];
        for (int j = 1; j < n; j++)
            ans += (a[i][j] * j - pre[j] + a[i][j]);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
