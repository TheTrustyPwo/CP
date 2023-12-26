#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k;
    for (int i = n - k; i <= n; i++) cout << i << ' ';
    for (int i = n - k - 1; i >= 1; i--) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
