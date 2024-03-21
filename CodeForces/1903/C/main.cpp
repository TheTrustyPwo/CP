#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int suf[n]; suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) suf[i] = suf[i + 1] + a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) ans += a[i];
    for (int i = 1; i < n; i++) if (suf[i] > 0) ans += suf[i];
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
