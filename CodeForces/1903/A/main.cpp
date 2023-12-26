#include <bits/stdc++.h>
using namespace std;
#define int long long

void test_case(int test) {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    if (k >= 2) cout << "YES\n";
    else {
        bool sorted = 1;
        for (int i = 1; i < n; i++) if (a[i] < a[i - 1]) sorted = 0;
        cout << (sorted ? "YES\n" : "NO\n");
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
