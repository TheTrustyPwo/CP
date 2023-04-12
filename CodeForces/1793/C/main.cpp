#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n - 1, mn = 1, mx = n;
    while (r - l > 2) {
        if (a[l] == mn) mn++, l++;
        else if (a[l] == mx) mx--, l++;
        else if (a[r] == mn) mn++, r--;
        else if (a[r] == mx) mx--, r--;
        else break;
    }

    if (r - l > 2) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    } else cout << -1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
