#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m; cin >> n >> m;
    if (m == 1) cout << 0 << '\n';
    else cout << min(m, n + 1) << '\n';
    for (int i = 0; i < min(m - 1, n); i++) {
        for (int j = i; j < m; j++) cout << j << ' ';
        for (int j = 0; j < i; j++) cout << j << ' ';
        cout << '\n';
    }
    for (int i = min(m - 1, n); i < n; i++) {
        for (int j = 0; j < m; j++) cout << j << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
