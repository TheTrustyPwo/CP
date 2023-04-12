#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int b[n]; for (int i = 0; i < n; i++) b[i] = 0;
    for (int i = 0; i < n; i++) {
        b[i] += a[i];
        if (i + a[i] < n) b[i + a[i]] += a[i];
    }
    cout << *max_element(b, b + n) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
