#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int mx, mn; cin >> mx >> mn;
    cout << (mx - mn) * 2 << '\n';
    for (int i = mx; i > mn; i--) cout << i << ' ';
    for (int i = mn; i < mx; i++) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
