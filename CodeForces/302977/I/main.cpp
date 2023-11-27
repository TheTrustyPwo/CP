#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q, t[1024];

void update(int p, int v) {
    for (t[p += n] = v; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
}
    
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, t[l++]);
        if (r & 1) res = max(res, t[--r]);
    }
    return res;
}

void test_case(int test) {
    cin >> n >> m >> q;
    bool g[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> g[i][j];

    for (int i = 0; i < n; i++) {
        int cur = 0, mx = 0;
        for (int j = 0; j <= m; j++)
            if (j == m || !g[i][j]) mx = max(mx, cur), cur = 0;
            else cur++;
        update(i, mx);
    }

    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        g[x][y] = !g[x][y];
        int cur = 0, mx = 0;
        for (int j = 0; j <= m; j++)
            if (j == m || !g[x][j]) mx = max(mx, cur), cur = 0;
            else cur++;
        update(x, mx);
        cout << query(0, n - 1) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
