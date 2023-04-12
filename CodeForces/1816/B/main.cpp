#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    cout << 2 * n << ' ';
    for (int i = 2; i <= n * 2 - 2; i += 2) cout << i << ' ';
    cout << '\n';
    for (int i = 1; i <= n * 2 - 2; i += 2) cout << i << ' ';
    cout << 2 * n - 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
