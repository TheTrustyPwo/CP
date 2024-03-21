#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, dsu[200005], sz[200005], p[200005];
vector<int> g[200005];
vector<pair<int, pair<int, int>>> edges;

int find(int v) {
    if (dsu[v] == v) return v;
    return dsu[v] = find(dsu[v]);
}

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    dsu[v] = u;
    sz[u] += sz[v];
    return true;
}

void dfs(int v, int par) {
    for (const auto u : g[v]) {
        if (u == par) continue;
        p[u] = v;
        dfs(u, v);
    }
}

void test_case(int test) {
    cin >> n >> m; edges.clear();
    for (int i = 1; i <= n; i++) dsu[i] = i, sz[i] = 1, g[i].clear();
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        edges.push_back({c, {u, v}});
    }

    sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());

    pair<int, int> last; int least;
    for (const auto it : edges) {
        int u = it.second.first, v = it.second.second;
        if (merge(u, v)) {
            g[u].push_back(v);
            g[v].push_back(u);
        } else {
            last = it.second;
            least = it.first;
        }
    }

    p[last.first] = -1;
    dfs(last.first, last.first);
    vector<int> ans;
    for (int node = last.second; node != -1; node = p[node]) {
        ans.push_back(node);
    }

    cout << least << ' ' << ans.size() << '\n';
    for (const auto it : ans) cout << it << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
