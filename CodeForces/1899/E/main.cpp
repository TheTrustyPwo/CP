#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int idx = 0, mn = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] < mn) {
            mn = a[i];
            idx = i;
        }
    }

    bool b = true;
    for (int i = idx; i < n - 1; i++) if (a[i + 1] < a[i]) b = false;
    if (!b) {
        cout << -1 << '\n';
        return;
    }

    cout << idx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
