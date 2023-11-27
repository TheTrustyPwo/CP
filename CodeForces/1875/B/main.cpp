#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, m, k; cin >> n >> m >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int b[m]; for (int i = 0; i < m; i++) cin >> b[i];

    int x = 0, y = 0;
    for (int i = 1 ; i < n ; i ++) if (a[i] < a[x]) x = i;
    for (int i = 1 ; i < m ; i ++) if (b[i] > b[y]) y = i;
    if (b[y] > a[x]) swap(a[x], b[y]);
    if (k % 2 == 0) {
        x = 0, y = 0;
        for (int i = 1 ; i < n ; i ++) if(a[i] > a[x]) x = i;
        for (int i = 1 ; i < m ; i ++) if(b[i] < b[y]) y = i;
        swap(a[x], b[y]);
    }
    long long ans = 0;
    for (int i = 0 ; i < n ; i ++) ans += a[i];
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}