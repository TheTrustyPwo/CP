#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
int parent[200005];
vector<vector<int>> a(200005, vector<int>(5, 0));

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (a[u][3] > a[v][3]) parent[v] = u;
    else parent[u] = v;
}

void test_case(int test) {
    cin >> n;
    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        a[i][4] = i;
    }
    sort(a.begin(), a.begin() + n);
    for (int i = 1; i < n; i++) if (a[i][0] <= a[i-1][3]) {
        merge(i - 1, i);
    }

    cin >> q;
    while (q--) {
        int x; cin >> x;
        int l = 0, r = n - 1, ans;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m][0] <= x) {
                ans = m;
                l = m + 1;
            } else r = m - 1;
        }
        cout << max(a[find(ans)][3], x) << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
