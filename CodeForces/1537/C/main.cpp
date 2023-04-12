#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    if (n == 2) {
        cout << a[0] << ' ' << a[1] << '\n';
        return;
    }

    int mn = 1e18, pos = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] < mn) {
            mn = a[i + 1] - a[i];
            pos = i + 1;
        }
    }

    for (int i = pos; i < n; i++) cout << a[i] << ' ';
    for (int i = 0; i < pos; i++) cout << a[i] << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
