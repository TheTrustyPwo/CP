#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n, k; cin >> n >> k; k++;
    int a[n]; bool b[k]{};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }

    int pre[n]; pre[0] = a[0];
    for (int i = 1; i < n; i++) pre[i] = max(pre[i - 1], a[i]);
    int suf[n]; suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], a[i]);

    for (int i = 1; i < k; i++) {
        if (!b[i]) { cout << 0 << ' '; continue; }
        int it1 = lower_bound(pre, pre + n, i) - pre;
        int it2 = upper_bound(suf, suf + n, i, greater<int>()) - suf - 1;
        int d = it2 - it1;
        cout << (d + 1) * 2 << ' ';
    } cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
