#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int mn = 1e9, cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= 0) cnt++;
        mn = min(mn, abs(x));
        sum += abs(x);
    }
    if (cnt & 1) cout << sum - 2 * mn << '\n';
    else cout << sum << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
