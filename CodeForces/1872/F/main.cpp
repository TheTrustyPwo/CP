#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n+1], c[n+1], in[n+1]{}, out[n+1]{};
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = x;
        in[x]++, out[i]++;
    } for (int i = 1; i <= n; i++) cin >> c[i];

    vector<int> ans; bool b[n+1]{};
    for (int i = 1; i <= n; i++) if (in[i] == 0)
        ans.push_back(i), in[a[i]]--, b[i] = 1;

    for (int i = 1; i <= n; i++) {
        if (b[i]) continue;
        vector<int> v; int cur = i, mn = 1e9, idx = -1;
        while (true) {
            if (c[i] > mn) {
                mn = c[i];
                idx = v.size();
            }
            v.push_back(cur);
            b[cur] = 1;
            cur = a[cur];
            if (b[cur]) break;
        }

        for (int i = idx + 1; i < v.size(); i++) ans.push_back(v[i]);
        for (int i = 0; i <= idx; i++) ans.push_back(v[i]);
    }

    for (const int u : ans) cout << u << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
