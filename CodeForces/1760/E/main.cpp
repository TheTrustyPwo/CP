#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    bool a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int ones[n]; ones[0] = 0;
    for (int i = 1; i < n; i++) ones[i] = ones[i - 1] + a[i - 1];
    int zeros[n]; zeros[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) zeros[i] = zeros[i + 1] + !a[i + 1];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) ans += zeros[i];
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (!a[i]) mx = max(mx, zeros[i] - ones[i]);
        else mx = max(mx, ones[i] - zeros[i]);
    }

    cout << ans + mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
