#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = 0, mx = 0;
        for (int j = 1; j < i; j++) cur += j * j, mx = max(mx, j * j);
        for (int j = i; j <= n; j++) cur += j * (n - (j - i)), mx = max(mx, j * (n - (j - i)));
        ans = max(ans, cur - mx);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
