#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int pre[30][n];
    for (int i = 0; i < 30; i++) {
        pre[i][0] = ((a[0] >> i) & 1);
        for (int j = 1; j < n; j++) {
            pre[i][j] = ((a[j] >> i) & 1);
            pre[i][j] += pre[i][j - 1];
        }
    }

    int q; cin >> q;
    while (q--) {
        int k, x; cin >> x >> k; x--;
        int l = x, r = n - 1, ans = x;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int res = 0;
            for (int i = 0; i < 30; i++) {
                int p;
                if (x == 0) p = pre[i][m];
                else p = pre[i][m] - pre[i][x - 1];
                if (p == m - x + 1) res = (res | (1 << i));
            }
            if (res >= k) ans = m, l = m + 1;
            else r = m - 1;
        }
        if (ans == x && a[x] < k) cout << -1 << ' ';
        else cout << ans + 1 << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
