#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int mn = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) continue;
        else {
            if (a[i] > mn) { cout << "No\n"; return; }
            mn = a[i];
        }
    }
    cout << "Yes\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
