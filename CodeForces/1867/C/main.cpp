#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int k = a[n - 1] + 1;
    for (int i = 0; i < n; i++) if (i != a[i]) {
        k = i;
        break;
    }

    cout << k << endl;
    while (true) {
        int t; cin >> t;
        if (t == -1) break;
        cout << t << endl;
    }
}

int32_t main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
