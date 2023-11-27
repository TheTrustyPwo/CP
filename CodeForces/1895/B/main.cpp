#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n * 2];
    for (int i = 0; i < n * 2; i++) cin >> a[i];
    sort(a, a + n + n);
    
    int d = a[n - 1] - a[0] + a[2 * n - 1] - a[n];
    cout << d << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ' << a[i + n] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
