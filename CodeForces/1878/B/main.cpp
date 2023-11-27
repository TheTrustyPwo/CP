#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case(int test) {
    int n; cin >> n;
    int a[n]; a[0] = 1; a[1] = 3;
    for (int i = 2; i < n; i++) a[i] = a[i-1] + 2;
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) test_case(i);
    return 0;
}
