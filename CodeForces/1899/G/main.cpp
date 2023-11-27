#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, timer, tin[100005], tout[100005], p[100005], a[100005];
vector<int> t[262144];
vector<int> g[100005];

void build(int idx, int l, int r) {
    if (l == r) { t[idx] = vector<int>(1, a[l]); return; }
    int m = (l + r) / 2;
    build(idx * 2, l, m);
    build(idx * 2 + 1, m + 1, r);
    merge(t[idx * 2].begin(), t[idx * 2].end(), t[idx * 2 + 1].begin(), t[idx * 2 + 1].end(), back_inserter(t[idx]));
}

int query(int idx, int l, int r, int tl, int tr, int mn, int mx) {
    if (tl > r || l > tr) return 0;
    if (l == tl && r == tr) {
        int res = lower_bound(t[idx].begin(), t[idx].end(), mx) -
            upper_bound(t[idx].begin(), t[idx].end(), mn);
        // cout << l << ' ' << r << ' ' << res << '\n';
        // cout << mn << ' ' << mx << '\n';
        // for (int x : t[idx]) cout << x << ' '; cout << '\n';
        return res;
    }
    int m = (l + r) / 2;
    return query(idx * 2, l, m, tl, min(m, tr), mn, mx) + query(idx * 2 + 1, m + 1, tr, max(m + 1, tl), tr, mn, mx);
}

void dfs(int v, int p) {
    tin[v] = timer++;
    for (const int u : g[v]) if (u != p) dfs(u, v);
    tout[v] = timer;
}

void test_case(int test) {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) cin >> p[i];

    timer = 1;
    dfs(1, -1);

    // for (int i = 1; i <= n; i++) cout << tin[i] << ' '; cout << '\n';

    for (int i = 1; i <= n; i++) a[i] = tin[p[i]];
    build(1, 1, n);

    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        int res = query(1, 1, n, l, r, tin[x], tout[x]);
        cout << (res ? "YES\n" : "NO\n");
    }

    cout << '\n';
    for (int i = 1; i <= n; i++) g[i].clear();
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
