#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 998244353;



int n, a[2005]; vector<int> g[1005];
unordered_set<int> st;
bool visited[1005]; int vis = 0;

void dfs(int v) {
    visited[v] = 1; vis++;
    for (const int u : g[v]) {
        if (visited[u]) continue;
        dfs(u);
    }
}

void test_case(int test) {
    cin >> n; for (int i = 0; i < n * 2; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) g[i].clear();
    st.clear();
    int cnt = 0, ans = 1;
    for (int i = 0; i < 2 * n; i++) {
        if (st.find(a[i]) != st.end()) {
            st.erase(a[i]);
            for (const int &u : st) g[a[i]].push_back(u);
        } else {
            st.insert(a[i]);
            for (const int &u : st) g[a[i]].push_back(u);
        }
        if (st.empty()) {
            cnt++; vis = 0;
            memset(visited, 0, sizeof(visited));
            dfs(a[i]);
            ans = (ans * ((vis * 2) % m)) % m;
        }
    }

    cout << cnt << ' ' << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}