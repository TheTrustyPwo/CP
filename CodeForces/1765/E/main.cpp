#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, a, b; cin >> n >> a >> b;
    if (b < a) cout << 1 << '\n';
    else cout << ((n + a - 1) / a) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
