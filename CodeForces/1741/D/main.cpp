#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n; int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) { cout << 0 << '\n'; return; }

    int cnt = 0;
    for (int b = n >> 1; b >= 1; b >>= 1) {
        // for (int i = 0; i < b; i++) cout << a[i] << ' '; cout << '\n';
        for (int i = 0; i < b; i++) {
            if ((a[i * 2] + 1) / 2 != (a[i * 2 + 1] + 1) / 2) {
                cout << -1 << '\n';
                return;
            }
            if (a[i * 2] > a[i * 2 + 1]) cnt++;
            a[i] = (a[i * 2] + 1) / 2;
        }
    }
    cout << cnt << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
