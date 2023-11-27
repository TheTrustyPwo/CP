#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    multiset<int> a[n]; int mn = 1e9;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x; mn = min(mn, x);
            a[i].insert(x);
        }
    }

    int pre[n]; pre[0] = *++a[0].begin();
    for (int i = 1; i < n; i++) pre[i] = pre[i-1] + *++a[i].begin();
    int suf[n]; suf[n-1] = *++a[n-1].begin();
    for (int i = n - 2; i >= 0; i--) suf[i] = suf[i+1] + *++a[i].begin();

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int res = (i == 0 ? 0 : pre[i-1]) + (i == n - 1 ? 0 : suf[i+1]);
        mx = max(mx, res);
    }

    cout << mx + mn << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
