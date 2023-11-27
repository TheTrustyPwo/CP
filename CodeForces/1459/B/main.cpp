#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n; cin >> n; int k = n / 2;
    if (n & 1) cout << 2 * (k + 1) * (k + 2);
    else cout << (k + 1) * (k + 1);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 1; i++) test_case(i);
    return 0;
}
