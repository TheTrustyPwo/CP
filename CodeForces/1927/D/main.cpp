#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, m; cin >> n; 
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    int t[n]; t[n - 1] = n - 1; int idx = n - 1, cur = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != cur) cur = a[i], idx = i, t[i] = idx;
        else t[i] = idx;
    }

    // for (int i = 0; i < n; i++) cout << t[i] << ' ';

    cin >> m;
    while (m--) {
        int x, y; cin >> x >> y; x--; y--;
        if (t[x] >= y) cout << -1 << ' ' << -1 << '\n';
        else cout << x + 1 << ' ' << t[x] + 2 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
