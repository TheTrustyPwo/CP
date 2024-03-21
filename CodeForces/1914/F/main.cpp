#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, timer = 1;
vector<int> g[200005];
int pre[200005], post[200005];

void dfs(int v, int p) {
    pre[v] = timer++;
    for (const int u : g[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        cnt[depth[u]]++;
        dfs(u, v);
    }
    post[v] = timer;
}

void test_case(int test) {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        g[p].push_back(i);
    }

    dfs(1, 1);
 
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
