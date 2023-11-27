#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int loc = 0, gl = -1e18;
    for (int i = 0; i < n; i++) {
        if (i > 0 && (abs(a[i]) % 2 == abs(a[i - 1]) % 2)) {
            loc = 0;
        }
        loc = max(a[i], a[i] + loc);
        gl = max(gl, loc);
        // cout << loc << ' ';
    }
    cout << gl << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
