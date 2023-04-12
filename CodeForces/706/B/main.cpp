#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int mini = upper_bound(a, a + n, x) - a;
        cout << mini << '\n';
    }

    return 0;
}
