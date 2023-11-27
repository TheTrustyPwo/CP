#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= a[i + 1]) continue;
        int b = (a[i] / a[i + 1]) + (a[i] % a[i + 1] != 0);
        int d = b - 1;
        ans += d;
        a[i] = a[i] / b;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
