#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1 && a[i] & 1) {
            ans -= a[i];
        } else if (i % 2 == 0 && a[i] % 2 == 0) {
            ans += a[i];
        }
    }

    if (ans == 0) cout << "Tie\n";
    else if (ans > 0) cout << "Alice\n";
    else cout << "Bob\n"; 
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
