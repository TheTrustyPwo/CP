#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    string ans = ""; bool b = 0;
    for (int i = 0; i < n / 2; i++) ans += (b ? "aa" : "bb"), b = !b;
    if (n & 1) ans += (b ? "a" : "b");
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    test_case(1);
    return 0;
}
