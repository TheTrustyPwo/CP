#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n; int mn = 1e9;
    int a[n], b[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        mn = min(mn, a[i]);
    }

    sort(b, b + n);
    bool f = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] % mn != 0 && a[i] != b[i]) f = 0;
    }
    cout << (f ? "YES\n" : "NO\n");
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
