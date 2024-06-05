#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, l, r; cin >> n >> l >> r;
    int a[n + 1]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    a[n] = 1e18;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (l - a[i] > a[n - 1]) continue;
        auto it1 = lower_bound(a + i + 1, a + n + 1, l - a[i]) - a;
        auto it2 = upper_bound(a + i + 1, a + n + 1, r - a[i]) - a - 1;
        cnt += (it2 - it1 + 1);
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
