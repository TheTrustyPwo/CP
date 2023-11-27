#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n; bitset<200005> b(0);
    for (int i = 0; i < n; i++) {
        int k; cin >> k; bitset<200005> c(0);
        for (int j = 0; j < k; j++) {
            int p; cin >> p;
            c.set(p);
        }
        if ((b | c) == b) {
            cout << "YES\n";
            return;
        }
        b |= c;
    }
    cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
