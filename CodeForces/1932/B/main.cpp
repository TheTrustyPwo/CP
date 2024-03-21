#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int wait = (a[i] - (ans % a[i])) % a[i];
        ans += wait;
        ans++;
    }
    cout << ans - 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
