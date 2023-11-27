#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int a, b, c; cin >> a >> b >> c;
    if (c % 2 == 0) {
        cout << (a > b ? "First\n" : "Second\n");
    } else cout << (a > b - 1 ? "First\n" : "Second\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
