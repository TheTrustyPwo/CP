#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int h[n]; for (int i = 0; i < n; i++) cin >> h[i];

    int cur = 0, res = 0, mx = 0, ptr = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > k) cur = 0, res = 0, ptr = i + 1;
        else if (i == 0 || h[i - 1] % h[i] == 0) {
            while (cur + a[i] > k && ptr <= i) cur -= a[ptr], ptr++, res--;
            cur += a[i], res++, mx = max(mx, res);
        } else cur = a[i], res = 1, ptr = i, mx = max(mx, res);
    }

    cout << max(mx, res) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
