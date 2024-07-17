#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 1e9 + 7;

int pre[200005];

void test_case(int test) {
    int n, k, sum = 0; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = (sum + a[i] + m) % m;
    }

    int cur = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        mx = max(mx, cur);
        if (cur < 0) cur = 0;
    }

    mx = (mx + m) % m;

    if (mx <= 0) sum = (sum + (mx * k) % m) % m;
    else sum = (sum + (pre[k] * mx - mx) % m) % m;
    cout << sum << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    pre[0] = 1;
    for (int i = 1; i <= 200000; i++) pre[i] = (pre[i - 1] * 2) % m;
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
