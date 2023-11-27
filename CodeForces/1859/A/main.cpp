#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int mx = *max_element(a, a + n);
    int cnt = 0; for (int i = 0; i < n; i++) if (a[i] == mx) cnt++;
    if (cnt == n) cout << "-1\n";
    else {
        cout << n - cnt << ' ' << cnt << '\n';
        for (int i = 0; i < n; i++) if (a[i] != mx) cout << a[i] << ' ';
        cout << '\n';
        for (int i = 0; i < cnt; i++) cout << mx << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
