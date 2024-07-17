#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, z = 0, d1[200005], d2[200005], t[200005];
vector<int> g[200005];

void dfs(int v, int p, int d) {
    if (z == 0) d1[v] = d;
    else d2[v] = d;
    for (const int u : g[v])
        if (u != p) dfs(u, v, d + 1);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 1, 0);
    int mx = 0, a = 1, b = 1;
    for (int i = 1; i <= n; i++)
        if (d1[i] > mx) mx = d1[i], a = i;
    z++;
    dfs(a, a, 0);
    for (int i = 1; i <= n; i++)
        if (d2[i] > mx) mx = d2[i], b = i;
    z--;
    dfs(b, b, 0);

    for (int i = 1; i <= n; i++) {
        int k = max(d2[i], d1[i]);
        t[k]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += t[i];
        cout << min(ans + 1, n) << ' ';
    }
}
