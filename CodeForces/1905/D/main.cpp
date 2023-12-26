#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n], b[n], da[n], db[n];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = i;
    }
    for (int i = 0; i < n; i++) b[i] = (a[i] - a[0] + n) % n;
    for (int i = 1; i < n; i++) da[i] = a[i]
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
