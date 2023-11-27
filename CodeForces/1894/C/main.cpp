#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k; k = min(n, k);
    int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];

    // bool ez = 0;
    // for (int i = 1; i <= n; i++) if (a[i] == n) ez = 1;
    // if (ez) {
    //     cout << "Yes\n";
    //     return;
    // }

    int cur = n, cnt = 0;
    while (cnt < n) {
        // cout << cur << ' ';
        if (a[cur] > n) break;
        cnt++;
        if (cur - a[cur] < 1) cur = n + (cur - a[cur]);
        else cur = cur - a[cur];
    }

    // cout << cnt << ' ';
    if (cnt >= k) cout << "Yes\n";
    else cout << "No\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
