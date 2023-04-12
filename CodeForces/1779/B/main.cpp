#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << "YES\n";
        bool b = true;
        for (int i = 0; i < n; i++) {
            cout << (b ? 1 : -1) << ' ';
            b = !b;
        }
        cout << '\n';
    } else if (n > 3) {
        cout << "YES\n";
        int x = (n - 3) / 2;
        bool b = true;
        for (int i = 0; i < n; i++) {
            cout << (b ? x : -x-1) << ' ';
            b = !b;
        }
    } else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
