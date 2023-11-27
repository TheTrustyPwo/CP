#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    bool b[n]; for (int i = 0; i < n; i++) cin >> b[i];

    int c = 0;
    for (int i = 0; i < n; i++) if (b[i]) {
        b[i] = 0;
        c += a[i];
        a[i] = 0;
    }

    int cur = 0, mx = 0; for (int i = 0; i < k; i++) cur += a[i]; mx = cur;
    for (int i = 1; i <= (n - k); i++) {
        cur -= a[i - 1];
        cur += a[i + k - 1];
        mx = max(mx, cur);
    }

    cout << c + mx;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
