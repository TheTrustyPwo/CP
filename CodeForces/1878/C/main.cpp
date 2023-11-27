#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k, x; cin >> n >> k >> x;
    int lower = (k * (k + 1)) / 2;
    int upper = n * k - (k * (k - 1)) / 2;
    if (x < lower || x > upper) cout << "NO\n";
    else cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
