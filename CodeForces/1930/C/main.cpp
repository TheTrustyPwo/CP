#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[300005];

void test_case(int test) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += i;
    }

    set<int> used, unused;
    set<int, greater<int>> ans;
    for (int i = 1; i <= n; i++) {
        if (used.find(a[i]) == used.end()) unused.insert(a[i]);
        int mx = *(--unused.upper_bound(a[i]));
        unused.erase(mx);
        if (used.find(mx - 1) == used.end()) unused.insert(mx - 1);
        used.insert(mx);
        ans.insert(mx);
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