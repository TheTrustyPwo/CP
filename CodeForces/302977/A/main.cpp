#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n;
    if (n & 1) cout << 0;
    else cout << (1 << (n >> 1));
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // int t; cin >> t;
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
