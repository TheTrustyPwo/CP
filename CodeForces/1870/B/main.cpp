#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, m; cin >> n >> m;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    bitset<30> b;
    for (int i = 0; i < m; i++) { int x; cin >> x; b |= x; }

    int s[30]{};
    for (int i = 0; i < n; i++) for (int j = 0; j < 30; j++)
        if ((a[i] & (1 << j)) != 0) s[j]++;

    int mn = 0, mx = 0;
    for (int i = 0; i < 30; i++) {
        if (s[i] & 1) {
            mx += (1 << i);
            if ((n & 1) || !b.test(i)) mn += (1 << i);
        } else {
            if ((n & 1) && b.test(i)) mx += (1 << i);
        }
    }

    cout << mn << ' ' << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
