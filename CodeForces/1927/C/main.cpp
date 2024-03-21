#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, m, k; cin >> n >> m >> k;
    set<int> s1, s2;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= k) s1.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (x <= k) s2.insert(x);
    }
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= k; i++) {
        bool b1 = s1.find(i) != s1.end();
        bool b2 = s2.find(i) != s2.end();
        if (!b1 && !b2) {
            cout << "NO\n";
            return;
        }
        if (b1 && !b2) c1++;
        if (!b1 && b2) c2++;
    }
    int tmp = k / 2;
    if (c1 > tmp || c2 > tmp) cout << "NO\n";
    else cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
