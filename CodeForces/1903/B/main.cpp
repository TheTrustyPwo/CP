#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int m[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> m[i][j];

    int a[n];
    for (int i = 0; i < n; i++) {
        int v = (1LL << 30) - 1;
        for (int j = 0; j < n; j++) if (i != j) v &= m[i][j];
        a[i] = v;
    }

    bool ok = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (i != j) if ((a[i] | a[j]) != m[i][j]) ok = 0;
    }

    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
    } else cout << "NO";
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
