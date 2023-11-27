#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int s1 = 0, s2 = 0, mn1 = 1e9, mn2 = 1e9;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s1 += x;
        mn1 = min(mn1, x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s2 += x;
        mn2 = min(mn2, x);
    }

    int a1 = s1 + mn2 * n, a2 = s2 + mn1 * n;
    cout << min(a1, a2) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
