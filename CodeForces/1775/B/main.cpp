#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<200005> b, c;

void test_case(int test) {
    int n, k, p; bool ans = 0; cin >> n; b.reset();
    while (n--) {
        cin >> k; c.reset();
        while (k--) {
            cin >> p;
            c.set(p);
        }
        if ((b | c) == b) ans = 1;
        b |= c;
    }
    cout << (ans ? "Yes\n" : "No\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
