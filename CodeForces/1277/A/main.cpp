#include <bits/stdc++.h>
using namespace std;
#define int long long

int pre[15];

void test_case(int test) {
    int n; cin >> n;
    int digits = 0;

    int tmp = n;
    while (tmp) {
        tmp /= 10;
        digits++;
    }

    int ans = (digits - 1) * 9;

    for (int i = 1; i <= 9; i++) {
        if (n >= pre[digits] * i) ans++;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    pre[1] = 1;
    for (int i = 2; i < 14; i++) pre[i] = pre[i - 1] * 10 + 1;
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
