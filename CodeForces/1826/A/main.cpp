#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (i < a[j]) cnt++;
        if (cnt == i) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
