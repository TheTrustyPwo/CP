#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    vector<int> g[n + 1];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (g[i].size() <= 1) cnt++;
    cout << (cnt + 1) / 2 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
