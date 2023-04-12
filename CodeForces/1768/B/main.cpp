#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void test_case(int test) {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int target = 1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == target) target++;
        else cnt++;
    }
    int x = cnt;
    if (x == 0) { cout << x << '\n'; return; }
    int ans = (x / k) + (x % k != 0);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
